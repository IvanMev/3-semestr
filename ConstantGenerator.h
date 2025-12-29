#pragma once
#include "Generator.h"

namespace miit::algebra
{
    class ConstantGenerator : public Generator
    {
    private:
        int value;

    public:
        ConstantGenerator(const int constant_value);
        int generate() const override;
    };
}






