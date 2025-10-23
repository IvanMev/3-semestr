#pragma once
#include "Matrix.h"
#include "Generator.h"

namespace miit::algebra
{
    class Exercise
    {
    protected:
        Matrix<int> matrix;
        Generator* generator;

    public:
        Exercise(size_t size, Generator* gen);
        virtual ~Exercise() = default;

        virtual void Task1() = 0;  // Заменить последний элемент массива, кратный 3, нулем
        virtual void Task2() = 0;  // Вставить число К после всех четных элементов
        virtual Matrix<int> Task3(const Matrix<int>& P) = 0;  // Сформировать массив M по правилу

        Matrix<int> get_matrix() const;
        void set_matrix(const Matrix<int>& new_matrix);
        void fill_matrix();
    };
}