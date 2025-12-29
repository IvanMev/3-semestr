#include "Task3Exercise.h"
#include "RandomGenerator.h"
#include "ConstantGenerator.h"
#include "IStreamGenerator.h"
#include <cmath>
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
    Task3Exercise::Task3Exercise(size_t size)
        : Exercise(size, nullptr)
    {
    }

    void Task3Exercise::SolveTask()
    {
    }
}

namespace miit::algebra
{
    Matrix<int> createArrayM(const Matrix<int>& P)
    {
        Matrix<int> M(P.get_size());
        for (size_t i = 0; i < P.get_size(); ++i)
        {
            if (i == 0 || i == P.get_size() - 1)
            {
                M[i] = 0;
            }
            else if (P[i] % 2 == 0)
            {
                M[i] = P[i] * std::abs(P[i]);
            }
            else
            {
                M[i] = P[i] * (static_cast<int>(i) + 1);
            }
        }
        return M;
    }

    void RunTask3()
    {
        std::cout << "\n=== Задача 3 ===" << std::endl;
        
        size_t size = 0;
        std::cout << "Введите размер массива P: ";
        std::cin >> size;
        
        if (size == 0)
        {
            std::cout << "Размер массива должен быть больше 0!" << std::endl;
            return;
        }
        
        Matrix<int> P(size);
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
        
        P.fill(*gen);
        std::cout << "Массив P: " << P.to_string() << std::endl;
        
        Matrix<int> M = createArrayM(P);
        std::cout << "Массив M: " << M.to_string() << std::endl;
    }
}