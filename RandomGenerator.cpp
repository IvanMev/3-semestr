#include "RandomGenerator.h"

namespace miit::algebra
{
    RandomGenerator::RandomGenerator(int min, int max)
        : min_val(min), max_val(max), generator(rd())
    {
    }

    int RandomGenerator::generate() const
    {
        std::uniform_int_distribution<int> distribution(min_val, max_val);
        return distribution(generator);
    }
}