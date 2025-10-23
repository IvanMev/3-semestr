#pragma once
#include "Exercise.h"

namespace miit::algebra
{
    class VariantExercise : public Exercise
    {
    private:
        int K;  // „исло дл¤ вставки в Task2

    public:
        VariantExercise(size_t size, Generator* gen, int K = 0);

        void Task1() override;
        void Task2() override;
        Matrix<int> Task3(const Matrix<int>& P) override;

        void set_K(int new_K);
        int get_K() const;
    };
}