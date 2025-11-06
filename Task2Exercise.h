#pragma once
#include "Exercise.h"

namespace miit::algebra
{
    class __declspec(dllexport) Task2Exercise : public Exercise
    {
    private:
        int K;

    public:
        Task2Exercise(size_t size, Generator* gen, int k = 0);
        void SolveTask() override;

        void insertKAfterEvenElements();
        int get_K() const;
        void set_K(int k);
    };
}
