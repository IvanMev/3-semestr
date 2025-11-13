#pragma once
#include "Matrix.h"
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

        Matrix<int>& get_matrix() { return matrix; }
        const Matrix<int>& get_matrix() const { return matrix; }
        size_t get_size() const { return matrix.get_size(); }

    protected:
        void fill_matrix();
    };
}