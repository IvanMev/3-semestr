#include <iostream>
#include "C:\Users\Ivan\source\repos\Задание1\Solver\Matrix.h"
#include "C:\Users\Ivan\source\repos\Задание1\Solver\RandomGenerator.h"
#include "C:\Users\Ivan\source\repos\Задание1\Solver\IStreamGenerator.h"
#include "C:\Users\Ivan\source\repos\Задание1\Solver\Task1Exercise.h"
#include "C:\Users\Ivan\source\repos\Задание1\Solver\Task2Exercise.h"
#include "C:\Users\Ivan\source\repos\Задание1\Solver\Task3Exercise.h"

using namespace miit::algebra;

void demonstrate_all_tasks()
{
    std::cout << "\n=== Демонстрация всех задач ===" << std::endl;

    // Task1
    std::cout << "\n--- Task 1 ---" << std::endl;
    RandomGenerator gen1(-100, 100);
    Task1Exercise task1(8, &gen1);
    task1.fill_matrix();
    std::cout << "До Task1: " << task1.get_matrix().to_string() << std::endl;
    task1.SolveTask();
    std::cout << "После Task1: " << task1.get_matrix().to_string() << std::endl;

    // Task2
    std::cout << "\n--- Task 2 ---" << std::endl;
    RandomGenerator gen2(-50, 50);
    Task2Exercise task2(6, &gen2, 777);
    task2.fill_matrix();
    std::cout << "До Task2: " << task2.get_matrix().to_string() << std::endl;
    task2.SolveTask();
    std::cout << "После Task2: " << task2.get_matrix().to_string() << std::endl;

    // Task3
    std::cout << "\n--- Task 3 ---" << std::endl;
    Matrix<int> P(5);
    RandomGenerator gen3(1, 10);
    P.fill(gen3);
    std::cout << "Массив P: " << P.to_string() << std::endl;

    Task3Exercise task3(0, nullptr);
    Matrix<int> M = task3.createArrayM(P);
    std::cout << "Массив M: " << M.to_string() << std::endl;
}

void demonstrate_user_input()
{
    std::cout << "\n=== Демонстрация с вводом с клавиатуры ===" << std::endl;
    std::cout << "Введите 5 чисел для матрицы: ";

    IStreamGenerator stream_gen;
    Task1Exercise manual_exercise(5, &stream_gen);
    manual_exercise.fill_matrix();

    std::cout << "Матрица из ввода: " << manual_exercise.get_matrix().to_string() << std::endl;
    manual_exercise.SolveTask();
    std::cout << "После Task1: " << manual_exercise.get_matrix().to_string() << std::endl;
}

int main()
{
    try
    {
        demonstrate_all_tasks();
        demonstrate_user_input();
        return 0;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }
}