#pragma once
#include "Matrix.h"
#include "Generator.h"

namespace miit::algebra
{
    class __declspec(dllexport) Exercise
    {
    protected:
        Matrix<int> matrix;
        Generator* generator;

    public:
        Exercise(size_t size, Generator* gen);
        virtual ~Exercise() = default;

        virtual void SolveTask() = 0;

        Matrix<int> get_matrix() const;
        void set_matrix(const Matrix<int>& new_matrix);
        void fill_matrix();
    };
}