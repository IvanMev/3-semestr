#pragma once
#include "Exercise.h"

namespace miit::algebra
{
    class __declspec(dllexport) Task3Exercise : public Exercise
    {
    public:
        Task3Exercise(size_t size, Generator* gen);
        void SolveTask() override;

        Matrix<int> createArrayM(const Matrix<int>& P);
    };
}
