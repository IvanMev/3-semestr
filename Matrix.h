#pragma once
#include <iostream>
#include <stdexcept>
#include <string>

namespace miit::algebra
{
    template<typename T>
    class Matrix
    {
    private:
        T* data;
        size_t size;

    public:
        Matrix();
        explicit Matrix(size_t size);
        Matrix(size_t size, const T& value);
        Matrix(const Matrix& other);
        Matrix(Matrix&& other) noexcept;

        ~Matrix();

        Matrix& operator=(const Matrix& other);
        Matrix& operator=(Matrix&& other) noexcept;

        T& operator[](size_t index);
        const T& operator[](size_t index) const;

        Matrix operator<<(size_t shift) const;
        Matrix operator>>(size_t shift) const;

        size_t get_size() const;
        std::string to_string() const;
        void resize(size_t new_size);

        T* get_data() { return data; }
        const T* get_data() const { return data; }

        template<typename Generator>
        void fill(Generator& gen);

    private:
        void copy_data(const T* source, T* destination, size_t count);
    };

}