#pragma once

#include <coroutine>
#include <exception>
#include <utility>

struct PreviousAwaiter {

    std::coroutine_handle<> mPrevious;

    bool await_ready() const noexcept { return false; }

    std::coroutine_handle<> await_suspend(std::coroutine_handle<> coroutine) const noexcept {
        if (mPrevious == nullptr) {
            return std::noop_coroutine();
        }
        return mPrevious;
    }

    void await_resume() const noexcept { }
};

template<class T>
struct Promise {

    std::coroutine_handle<> mPrevious{};
    std::exception_ptr mException{};

    Promise & operator = (Promise &&) = delete;

    std::coroutine_handle<Promise> get_return_object() {
        return std::coroutine_handle<Promise>::from_promise(*this);
    }

    auto initial_suspend() noexcept {
        return std::suspend_always();
    }

    // 默认Promise在协程结束后返回调用的协程
    auto final_suspend() noexcept {
        return PreviousAwaiter(mPrevious);
    }

    void return_value(T _value) {
        new (&m_Value) T(std::move(_value));
    }

    // 捕获异常
    void unhandled_exception() {
        mException = std::current_exception();
    }

    T m_Value;

    T result() {
        if (mException) {
            std::rethrow_exception(mException);
        }
        T ret = std::move(m_Value);
        m_Value.~T();
        return ret;
    }
};

// Promise 模板类需要对 void 进行特化
template<>
struct Promise<void> {

    std::coroutine_handle<> mPrevious{};
    std::exception_ptr mException{};

    Promise() = default;
    Promise(Promise &&) = delete;
    ~Promise() = default;

    std::coroutine_handle<Promise> get_return_object() {
        return std::coroutine_handle<Promise>::from_promise(*this);
    }

    auto initial_suspend() noexcept {
        return std::suspend_always();
    }

    // 协程结束后返回调用的协程
    auto final_suspend() noexcept {
        return PreviousAwaiter(mPrevious);
    }

    void return_void() {}

    // 捕获异常
    void unhandled_exception() {
        mException = std::current_exception();
    }

    void result() {
        if (mException) {
            std::rethrow_exception(mException);
        }
    }
};

template<class T = void, class P = Promise<T>>
struct Task {

    using promise_type = P;

    std::coroutine_handle<promise_type> mCoroutine;

    Task(std::coroutine_handle<promise_type> Coroutine)
        : mCoroutine(Coroutine) {}

    Task(Task &&that) noexcept : mCoroutine(that.mCoroutine) {
        that.mCoroutine = nullptr;
    }

    Task &operator=(Task &&that) noexcept {
        std::swap(mCoroutine, that.mCoroutine);
    }

    ~Task() {
        if (mCoroutine)
            mCoroutine.destroy();
    }
    
    struct taskAwaiter {
        bool await_ready() const noexcept { return false; }

        std::coroutine_handle<> await_suspend(std::coroutine_handle<> coroutine) const noexcept {
            mCoroutine.promise().mPrevious = coroutine;
            return mCoroutine;
        }

        T await_resume() const noexcept {
            //return mCoroutine.promise().m_Value;
            return mCoroutine.promise().result();
        }

        std::coroutine_handle<promise_type> mCoroutine;
    };

    //重载 co_await 使得可以在协程以 co_await 调用 Task（调用完返回当前协程）
    auto operator co_await() const {
        return taskAwaiter(mCoroutine);
    }

    // 添加一个coroutine_handle<promise_type>到coroutine_handle<>的转换
    operator std::coroutine_handle<>() const noexcept {
        return mCoroutine;
    }

};