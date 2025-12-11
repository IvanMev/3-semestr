#pragma once
#include "Matrix.h"
#include "Generator.h"

namespace miit::algebra
{
    class __declspec(dllexport) Exercise
    {
    public:
        Matrix<int> matrix;
        Generator* generator;

    public:
        Exercise(const size_t size, Generator* gen);
        virtual ~Exercise() = default;

        virtual void SolveTask() = 0;

    protected:
        void fill_matrix();
    };
}
