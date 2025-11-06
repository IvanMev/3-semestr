#include "RandomGenerator.h"

namespace miit::algebra
{
    RandomGenerator::RandomGenerator(int min, int max)
        : distribution(std::uniform_int_distribution<int>(min, max))
    {
        generator = std::mt19937(std::random_device{}());
    }

    int RandomGenerator::generate() const
    {
        return distribution(generator);
    }
}