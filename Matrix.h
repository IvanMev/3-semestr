#pragma once
#include <iostream>
#include <stdexcept>

namespace miit::algebra
{
    template<typename T>
    class Matrix
    {
    private:
        T* data;
        size_t size;

    public:
        // Конструкторы
        Matrix();
        explicit Matrix(size_t size);
        Matrix(size_t size, const T& value);
        Matrix(const Matrix& other);
        Matrix(Matrix&& other) noexcept;

        // Деструктор
        ~Matrix();

        // Операторы присваивания
        Matrix& operator=(const Matrix& other);
        Matrix& operator=(Matrix&& other) noexcept;

        // Операторы доступа
        T& operator[](size_t index);
        const T& operator[](size_t index) const;
        T& operator*();
        const T& operator*() const;

        // Операторы сдвига
        Matrix operator<<(size_t shift) const;
        Matrix operator>>(size_t shift) const;

        // Методы
        size_t get_size() const;
        std::string to_string() const;
        void resize(size_t new_size);

        // Заполнение массива
        template<typename Generator>
        void fill(Generator& gen);

    private:
        void copy_data(const T* source, T* destination, size_t count);
    };
}
