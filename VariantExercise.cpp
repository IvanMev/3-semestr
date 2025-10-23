#include "VariantExercise.h"
#include <cmath>

namespace miit::algebra
{
    VariantExercise::VariantExercise(size_t size, Generator* gen, int K)
        : Exercise(size, gen), K(K) {
    }

    void VariantExercise::Task1()
    {
        int last_index = -1;
        for (size_t i = 0; i < matrix.get_size(); ++i)
        {
            if (matrix[i] % 3 == 0)
            {
                last_index = i;
            }
        }

        if (last_index != -1)
        {
            matrix[last_index] = 0;
        }
    }

    void VariantExercise::Task2()
    {
        size_t original_size = matrix.get_size();
        size_t even_count = 0;

        // Подсчет четных элементов
        for (size_t i = 0; i < original_size; ++i)
        {
            if (matrix[i] % 2 == 0)
            {
                even_count++;
            }
        }

        // Создание нового массива
        Matrix<int> new_matrix(original_size + even_count);
        size_t new_index = 0;

        for (size_t i = 0; i < original_size; ++i)
        {
            new_matrix[new_index++] = matrix[i];
            if (matrix[i] % 2 == 0)
            {
                new_matrix[new_index++] = K;
            }
        }

        matrix = new_matrix;
    }

    Matrix<int> VariantExercise::Task3(const Matrix<int>& P)
    {
        size_t size = P.get_size();
        Matrix<int> M(size);

        for (size_t i = 0; i < size; ++i)
        {
            if (i == 0 || i == size - 1)
            {
                M[i] = 0;
            }
            else if ((i + 1) % 4 == 0)  // каждый четвертый элемент (индексация с 0)
            {
                M[i] = 4 * std::abs(P[i]);
            }
            else
            {
                M[i] = P[i] * (i + 1);
            }
        }

        return M;
    }

    void VariantExercise::set_K(int new_K)
    {
        K = new_K;
    }

    int VariantExercise::get_K() const
    {
        return K;
    }
}