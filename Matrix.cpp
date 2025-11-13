#include "Matrix.h"
#include <sstream>

namespace miit::algebra
{
    template<typename T>
    Matrix<T>::Matrix() : data(nullptr), size(0) {}

    template<typename T>
    Matrix<T>::Matrix(size_t size) : size(size)
    {
        data = new T[size]{};
    }

    template<typename T>
    Matrix<T>::Matrix(size_t size, const T& value) : size(size)
    {
        data = new T[size];
        for (size_t i = 0; i < size; ++i)
        {
            data[i] = value;
        }
    }

    template<typename T>
    Matrix<T>::Matrix(const Matrix& other) : size(other.size)
    {
        data = new T[size];
        copy_data(other.data, data, size);
    }

    template<typename T>
    Matrix<T>::Matrix(Matrix&& other) noexcept : data(other.data), size(other.size)
    {
        other.data = nullptr;
        other.size = 0;
    }

    template<typename T>
    Matrix<T>::~Matrix()
    {
        delete[] data;
    }

    template<typename T>
    Matrix<T>& Matrix<T>::operator=(const Matrix& other)
    {
        if (this != &other)
        {
            delete[] data;
            size = other.size;
            data = new T[size];
            copy_data(other.data, data, size);
        }
        return *this;
    }

    template<typename T>
    Matrix<T>& Matrix<T>::operator=(Matrix&& other) noexcept
    {
        if (this != &other)
        {
            delete[] data;
            data = other.data;
            size = other.size;
            other.data = nullptr;
            other.size = 0;
        }
        return *this;
    }

    template<typename T>
    T& Matrix<T>::operator[](size_t index)
    {
        if (index >= size)
        {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    template<typename T>
    const T& Matrix<T>::operator[](size_t index) const
    {
        if (index >= size)
        {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    template<typename T>
    Matrix<T> Matrix<T>::operator<<(size_t shift) const
    {
        Matrix result(size);
        for (size_t i = 0; i < size; ++i)
        {
            result[(i + shift) % size] = data[i];
        }
        return result;
    }

    template<typename T>
    Matrix<T> Matrix<T>::operator>>(size_t shift) const
    {
        Matrix result(size);
        for (size_t i = 0; i < size; ++i)
        {
            result[i] = data[(i + shift) % size];
        }
        return result;
    }

    template<typename T>
    size_t Matrix<T>::get_size() const
    {
        return size;
    }

    template<typename T>
    std::string Matrix<T>::to_string() const
    {
        std::ostringstream oss;
        oss << "[";
        for (size_t i = 0; i < size; ++i)
        {
            oss << data[i];
            if (i < size - 1)
            {
                oss << ", ";
            }
        }
        oss << "]";
        return oss.str();
    }

    template<typename T>
    void Matrix<T>::resize(size_t new_size)
    {
        if (new_size == size) return;

        T* new_data = new T[new_size]{};
        size_t copy_size = (new_size < size) ? new_size : size;
        copy_data(data, new_data, copy_size);

        delete[] data;
        data = new_data;
        size = new_size;
    }

    template<typename T>
    template<typename Generator>
    void Matrix<T>::fill(Generator& gen)
    {
        for (size_t i = 0; i < size; ++i)
        {
            data[i] = gen.generate();
        }
    }

    template<typename T>
    void Matrix<T>::copy_data(const T* source, T* destination, size_t count)
    {
        for (size_t i = 0; i < count; ++i)
        {
            destination[i] = source[i];
        }
    }

    template class Matrix<int>;
    template class Matrix<double>;
}