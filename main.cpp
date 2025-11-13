#include <iostream>
#include "C:\Users\Ivan\source\repos\Задание1\Solver\Matrix.h"
#include "C:\Users\Ivan\source\repos\Задание1\Solver\RandomGenerator.h"
#include "C:\Users\Ivan\source\repos\Задание1\Solver\IStreamGenerator.h"
#include "C:\Users\Ivan\source\repos\Задание1\Solver\Generator.h"
#include "C:\Users\Ivan\source\repos\Задание1\Solver\Task1Exercise.h"
#include "C:\Users\Ivan\source\repos\Задание1\Solver\Task2Exercise.h"
#include "C:\Users\Ivan\source\repos\Задание1\Solver\Task3Exercise.h"

using namespace miit::algebra;

void demonstrate_all_tasks()
{
    std::cout << "\nДемонстрация всех задач" << std::endl;

    std::cout << "\nTask 1" << std::endl;
    RandomGenerator gen1(-100, 100);
    Task1Exercise task1(8, &gen1);
    task1.SolveTask();

    std::cout << "\nTask 2" << std::endl;
    RandomGenerator gen2(-50, 50);
    Task2Exercise task2(6, &gen2, 777);
    task2.SolveTask();

    std::cout << "\nTask 3" << std::endl;
    Matrix<int> P(5);
    RandomGenerator gen3(1, 10);
    P.fill(gen3);
    std::cout << "Массив P: " << P.to_string() << std::endl;

    RandomGenerator gen4(-20, 20);
    Task3Exercise task3(5, &gen4);
    Matrix<int> M = task3.createArrayM(P);
    std::cout << "Массив M: " << M.to_string() << std::endl;
}

void demonstrate_constant_generator()
{
    std::cout << "\nДемонстрация Generator" << std::endl;

    ConstantGenerator const_gen(42);
    Task1Exercise const_task(5, &const_gen);
    const_task.SolveTask();
}

void demonstrate_user_input()
{
    std::cout << "\nДемонстрация с вводом с клавиатуры" << std::endl;

    std::cout << "Введите 5 чисел для матрицы: ";
    IStreamGenerator stream_gen;
    Task1Exercise manual_exercise(5, &stream_gen);
    manual_exercise.SolveTask();
}

int main()
{
    try
    {
        demonstrate_all_tasks();
        demonstrate_constant_generator();
        demonstrate_user_input();
        return 0;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }
}