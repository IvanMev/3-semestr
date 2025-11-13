#pragma once

namespace miit::algebra
{
    class Generator
    {
    public:
        virtual ~Generator() = default;
        virtual int generate() const = 0;
    };

    class ConstantGenerator : public Generator
    {
    private:
        int value;

    public:
        ConstantGenerator(int constant_value) : value(constant_value) {}

        int generate() const override
        {
            return value;
        }
    };
}