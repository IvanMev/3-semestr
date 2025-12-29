#pragma once
#include "Generator.h"
#include <random>

namespace miit::algebra
{
    class RandomGenerator : public Generator
    {
    private:
        int min_val;
        int max_val;
        mutable std::random_device rd;
        mutable std::mt19937 generator;

    public:
        RandomGenerator(const int min,const int max);
        int generate() const override;
    };
}