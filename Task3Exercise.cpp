#include "Task3Exercise.h"
#include "RandomGenerator.h"
#include "ConstantGenerator.h"
#include "IStreamGenerator.h"
#include <cmath>
#include <iostream>
#include <memory>

namespace miit::algebra
{
    Task3Exercise::Task3Exercise(size_t size)
        : Exercise(size, nullptr)
    {
    }

    void Task3Exercise::SolveTask()
    {
    }

    Matrix<int> Task3Exercise::createArrayM(const Matrix<int>& P)
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

    void Task3Exercise::Run()
    {
        std::cout << "\n=== Задача 3 ===" << std::endl;
        
        size_t size;
        std::cout << "Введите размер массива P: ";
        std::cin >> size;
        
        if (size == 0)
        {
            std::cout << "Размер массива должен быть больше 0!" << std::endl;
            return;
        }
        
        Matrix<int> P(size);
        int choice;
        std::cout << "\nВыберите генератор:" << std::endl;
        std::cout << "1. Случайный генератор (Random)" << std::endl;
        std::cout << "2. Генератор константы (Constant)" << std::endl;
        std::cout << "3. Генератор из потока ввода (IStream)" << std::endl;
        std::cout << "Ваш выбор: ";
        std::cin >> choice;
        
        std::unique_ptr<Generator> gen;
        switch (choice)
        {
        case 1:
        {
            int min_val, max_val;
            std::cout << "Введите минимальное значение: ";
            std::cin >> min_val;
            std::cout << "Введите максимальное значение: ";
            std::cin >> max_val;
            gen = std::make_unique<RandomGenerator>(min_val, max_val);
            break;
        }
        case 2:
        {
            int constant_value;
            std::cout << "Введите константное значение: ";
            std::cin >> constant_value;
            gen = std::make_unique<ConstantGenerator>(constant_value);
            break;
        }
        case 3:
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
        
        Task3Exercise task3(size);
        Matrix<int> M = task3.createArrayM(P);
        std::cout << "Массив M: " << M.to_string() << std::endl;
    }
}