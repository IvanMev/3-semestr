#pragma once
#include "Generator.h"
#include <random>

namespace miit::algebra
{
    class RandomGenerator : public Generator
    {
    private:
        std::uniform_int_distribution<int> distribution;
        mutable std::mt19937 generator;

    public:
        RandomGenerator(int min, int max);
        int generate() const override;
    };
}