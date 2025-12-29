#include "Task1Exercise.h"
#include "RandomGenerator.h"
#include "ConstantGenerator.h"
#include "IStreamGenerator.h"
#include <iostream>
#include <memory>

namespace miit::algebra
{
    enum class GeneratorType
    {
        Random = 1,
        Constant = 2,
        IStream = 3
    };
    Task1Exercise::Task1Exercise(size_t size, Generator* gen)
        : Exercise(size, gen)
    {
    }

    void Task1Exercise::SolveTask()
    {
        replaceLastMultipleOfThree();
    }

    void Task1Exercise::replaceLastMultipleOfThree()
    {
        int last_index = -1;
        for (size_t i = 0; i < matrix.get_size(); ++i)
        {
            if (matrix[i] % 3 == 0)
            {
                last_index = static_cast<int>(i);
            }
        }

        if (last_index != -1)
        {
            matrix[last_index] = 0;
        }
    }
}

namespace miit::algebra
{
    void RunTask1()
    {
        std::cout << "\n=== Задача 1 ===" << std::endl;
        
        size_t size = 0;
        std::cout << "Введите размер матрицы: ";
        std::cin >> size;
        
        if (size == 0)
        {
            std::cout << "Размер матрицы должен быть больше 0!" << std::endl;
            return;
        }
        
        int choice = 0;
        std::cout << "\nВыберите генератор:" << std::endl;
        std::cout << static_cast<int>(GeneratorType::Random) << ". Случайный генератор (Random)" << std::endl;
        std::cout << static_cast<int>(GeneratorType::Constant) << ". Генератор константы (Constant)" << std::endl;
        std::cout << static_cast<int>(GeneratorType::IStream) << ". Генератор из потока ввода (IStream)" << std::endl;
        std::cout << "Ваш выбор: ";
        std::cin >> choice;
        
        std::unique_ptr<Generator> gen;
        switch (static_cast<GeneratorType>(choice))
        {
        case GeneratorType::Random:
        {
            int min_val = 0, max_val = 0;
            std::cout << "Введите минимальное значение: ";
            std::cin >> min_val;
            std::cout << "Введите максимальное значение: ";
            std::cin >> max_val;
            gen = std::make_unique<RandomGenerator>(min_val, max_val);
            break;
        }
        case GeneratorType::Constant:
        {
            int constant_value = 0;
            std::cout << "Введите константное значение: ";
            std::cin >> constant_value;
            gen = std::make_unique<ConstantGenerator>(constant_value);
            break;
        }
        case GeneratorType::IStream:
        {
            gen = std::make_unique<IStreamGenerator>();
            break;
        }
        default:
            gen = std::make_unique<ConstantGenerator>(0);
            break;
        }
        
        Task1Exercise task1(size, gen.get());
        task1.SolveTask();
        
        std::cout << "Результат: " << task1.matrix.to_string() << std::endl;
    }
}