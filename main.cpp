#include <iostream>
#include <locale>
#include "C:\Users\Ivan\source\repos\Задание1\Solver\Task1Exercise.h"
#include "C:\Users\Ivan\source\repos\Задание1\Solver\Task2Exercise.h"
#include "C:\Users\Ivan\source\repos\Задание1\Solver\Task3Exercise.h"

using namespace miit::algebra;

enum class TaskNumber
{
    Task1 = 1,
    Task2 = 2,
    Task3 = 3,
    Exit = 0
};


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
            std::cout << static_cast<int>(TaskNumber::Task1) << ". Задача 1" << std::endl;
            std::cout << static_cast<int>(TaskNumber::Task2) << ". Задача 2" << std::endl;
            std::cout << static_cast<int>(TaskNumber::Task3) << ". Задача 3" << std::endl;
            std::cout << static_cast<int>(TaskNumber::Exit) << ". Выход" << std::endl;
            std::cout << "Ваш выбор: ";
            std::cin >> choice;
            
            switch (static_cast<TaskNumber>(choice))
            {
            case TaskNumber::Task1:
                Task1Exercise::Run();
                break;
            case TaskNumber::Task2:
                Task2Exercise::Run();
                break;
            case TaskNumber::Task3:
                Task3Exercise::Run();
                break;
            case TaskNumber::Exit:
                std::cout << "Выход из программы." << std::endl;
                break;
            }
        } while (choice != static_cast<int>(TaskNumber::Exit));
        
        return 0;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }
}