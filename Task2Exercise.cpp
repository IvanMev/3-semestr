#include "Task2Exercise.h"
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
    Task2Exercise::Task2Exercise(size_t size, Generator* gen, int k)
        : Exercise(size, gen), K(k)
    {
    }

    void Task2Exercise::SolveTask()
    {
        insertKAfterEvenElements();
    }

    void Task2Exercise::insertKAfterEvenElements()
    {
        for (size_t i = 0; i < matrix.get_size(); ++i)
        {
            if (matrix[i] % 2 == 0)
            {
                matrix[i] = K;
            }
        }
    }

    int Task2Exercise::get_K() const
    {
        return K;
    }

    void Task2Exercise::set_K(int k)
    {
        K = k;
    }
}

namespace miit::algebra
{
    void RunTask2()
    {
        std::cout << "\n=== Задача 2 ===" << std::endl;
        
        size_t size = 0;
        std::cout << "Введите размер матрицы: ";
        std::cin >> size;
        
        if (size == 0)
        {
            std::cout << "Размер матрицы должен быть больше 0!" << std::endl;
            return;
        }
        
        int k = 0;
        std::cout << "Введите значение K: ";
        std::cin >> k;
        
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
        
        Task2Exercise task2(size, gen.get(), k);
        task2.SolveTask();
        
        std::cout << "Результат: " << task2.matrix.to_string() << std::endl;
    }
}