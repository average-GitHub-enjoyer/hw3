
#include <cstdlib>
#include <iostream>

template<typename T>
class array_bundle {
public:
    array_bundle() = default;

    array_bundle(size_t size) {
        if (size == 0) {
            rawptr = nullptr;
        } else {
            rawptr = new T[size]{};
        }
    }

    explicit array_bundle(T ptr) noexcept {
        rawptr = ptr;
    }

    array_bundle(const array_bundle &other_bundle) = delete;

    array_bundle &operator=(const array_bundle &other_bundle) = delete;

    T &operator[](size_t index) noexcept {
        return rawptr[index];
    }

    const T &operator[](size_t index) const noexcept {
        return const_cast<const T &>(rawptr[index]);
    }

    explicit operator bool() const {
        return rawptr != nullptr;
    }

    T *Release() noexcept {
        T ptr = rawptr;
        rawptr = nullptr;
        return ptr;
    }

//GETTER
    T * Get() const noexcept {
        return rawptr;
    }

    ~array_bundle() {
        delete[] rawptr;
    }

    void swap(array_bundle &other) noexcept {
        std::swap(rawptr, other.rawptr);
    }

private:
    T *rawptr;
};
