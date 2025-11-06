#pragma once
#include "Exercise.h"

namespace miit::algebra
{
    class __declspec(dllexport) Task1Exercise : public Exercise
    {
    public:
        Task1Exercise(size_t size, Generator* gen);
        void SolveTask() override;

        void replaceLastMultipleOfThree();
    };
}