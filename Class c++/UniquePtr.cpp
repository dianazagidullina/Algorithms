#include<cstddef>
#include<utility>

using namespace std;

template<typename T>
class UniquePtr {
private:
    T *ptr_;

public:
    UniquePtr() noexcept {
        ptr_ = nullptr;
    }

    explicit UniquePtr(T *val) noexcept {
        ptr_ = val;
        val = nullptr;
    }

    UniquePtr(const UniquePtr &) = delete;

    UniquePtr &operator=(const UniquePtr &) = delete;

    UniquePtr& operator = (nullptr_t) noexcept  {
        release();
    }

    UniquePtr(UniquePtr&& now) noexcept {
        ptr_ = std::move(now.release());
    }

    UniquePtr &operator = (UniquePtr&& now) noexcept {
        reset(now.release());
        return *this;
    }

    T &operator*() {
        return *ptr_;
    }

    T &operator*() const {
        return *ptr_;
    }

    T *operator->() const noexcept {
        return ptr_;
    }

    T *get() const noexcept {
        return ptr_;
    }

    T *release() noexcept {
        auto ptr_new = ptr_;
        ptr_ = nullptr;
        return ptr_new;
    }

    void reset(T *ptr) noexcept {
        auto ptr_new = ptr_;
        ptr_ = ptr;
        if (ptr_new) {
            delete ptr_new;
        }
    }

    void swap(UniquePtr &other) noexcept {
        std::swap(other.ptr_, ptr_);
    }

    explicit operator bool() const noexcept {
        if (ptr_ == nullptr) {
            return false;
        } else {
            return true;
        }
    }

    ~UniquePtr() {
        if (ptr_) {
            delete  ptr_;
        }
        ptr_ = nullptr;
    }
};