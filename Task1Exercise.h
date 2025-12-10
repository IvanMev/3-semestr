#pragma once
#include "Exercise.h"

namespace miit::algebra
{
    class __declspec(dllexport) Task1Exercise : public Exercise
    {
    public:
        Task1Exercise(size_t size, Generator* gen);
        ~Task1Exercise() override = default;
        void SolveTask() override;

    private:
        void replaceLastMultipleOfThree();
    };
}