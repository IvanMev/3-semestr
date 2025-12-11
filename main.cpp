#include <iostream>
#include <memory>
#include <string>
#include <locale>
#include "C:\Users\Ivan\source\repos\Задание1\Solver\Matrix.h"
#include "C:\Users\Ivan\source\repos\Задание1\Solver\RandomGenerator.h"
#include "C:\Users\Ivan\source\repos\Задание1\Solver\IStreamGenerator.h"
#include "C:\Users\Ivan\source\repos\Задание1\Solver\ConstantGenerator.h"
#include "C:\Users\Ivan\source\repos\Задание1\Solver\Generator.h"
#include "C:\Users\Ivan\source\repos\Задание1\Solver\Task1Exercise.h"
#include "C:\Users\Ivan\source\repos\Задание1\Solver\Task2Exercise.h"
#include "C:\Users\Ivan\source\repos\Задание1\Solver\Task3Exercise.h"

using namespace miit::algebra;

std::unique_ptr<Generator> choose_generator(const std::string& task_name)
{
    int choice;
    std::cout << "\nВыберите генератор для " << task_name << ":" << std::endl;
    std::cout << "1. Случайный генератор (Random)" << std::endl;
    std::cout << "2. Генератор константы (Constant)" << std::endl;
    std::cout << "3. Генератор из потока ввода (IStream)" << std::endl;
    std::cout << "Ваш выбор: ";
    std::cin >> choice;

    switch (choice)
    {
    case 1:
    {
        int min_val, max_val;
        std::cout << "Введите минимальное значение: ";
        std::cin >> min_val;
        std::cout << "Введите максимальное значение: ";
        std::cin >> max_val;
        return std::make_unique<RandomGenerator>(min_val, max_val);
    }
    case 2:
    {
        int constant_value;
        std::cout << "Введите константное значение: ";
        std::cin >> constant_value;
        return std::make_unique<ConstantGenerator>(constant_value);
    }
    case 3:
    {
        return std::make_unique<IStreamGenerator>();
    }
    default:
        std::cout << "Неверный выбор, используется генератор константы со значением 0" << std::endl;
        return std::make_unique<ConstantGenerator>(0);
    }
}

void solve_task1()
{
    std::cout << "\n=== Задача 1 ===" << std::endl;
    
    size_t size;
    std::cout << "Введите размер матрицы: ";
    std::cin >> size;
    
    if (size == 0)
    {
        std::cout << "Размер матрицы должен быть больше 0!" << std::endl;
        return;
    }
    
    auto gen = choose_generator("Задачи 1");
    Task1Exercise task1(size, gen.get());
    task1.SolveTask();
    
    std::cout << "Результат: " << task1.matrix.to_string() << std::endl;
}

void solve_task2()
{
    std::cout << "\n=== Задача 2 ===" << std::endl;
    
    size_t size;
    std::cout << "Введите размер матрицы: ";
    std::cin >> size;
    
    if (size == 0)
    {
        std::cout << "Размер матрицы должен быть больше 0!" << std::endl;
        return;
    }
    
    int k;
    std::cout << "Введите значение K: ";
    std::cin >> k;
    
    auto gen = choose_generator("Задачи 2");
    Task2Exercise task2(size, gen.get(), k);
    task2.SolveTask();
    
    std::cout << "Результат: " << task2.matrix.to_string() << std::endl;
}

void solve_task3()
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
    auto gen = choose_generator("массива P");
    P.fill(*gen);
    std::cout << "Массив P: " << P.to_string() << std::endl;
    
    Task3Exercise task3(size);
    Matrix<int> M = task3.createArrayM(P);
    std::cout << "Массив M: " << M.to_string() << std::endl;
}

int main()
{
    try
    {
        std::setlocale(LC_ALL, "Russian");
        
        std::cout << "=== Решение задач ===" << std::endl;
        std::cout << "Пользователь задает размер матрицы и способ ее заполнения, затем решаются задачи" << std::endl;
        
        int choice;
        do
        {
            std::cout << "\nВыберите задачу для решения:" << std::endl;
            std::cout << "1. Задача 1" << std::endl;
            std::cout << "2. Задача 2" << std::endl;
            std::cout << "3. Задача 3" << std::endl;
            std::cout << "0. Выход" << std::endl;
            std::cout << "Ваш выбор: ";
            std::cin >> choice;
            
            switch (choice)
            {
            case 1:
                solve_task1();
                break;
            case 2:
                solve_task2();
                break;
            case 3:
                solve_task3();
                break;
            case 0:
                std::cout << "Выход из программы." << std::endl;
                break;
            default:
                std::cout << "Неверный выбор. Попробуйте снова." << std::endl;
                break;
            }
        } while (choice != 0);
        
        return 0;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }
}