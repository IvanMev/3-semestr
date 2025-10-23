#include <iostream>
#include "C:\Users\Ivan\source\repos\Задание1\Solver\Matrix.h"
#include "C:\Users\Ivan\source\repos\Задание1\Solver\RandomGenerator.h"
#include "C:\Users\Ivan\source\repos\Задание1\Solver\IStreamGenerator.h"
#include "C:\Users\Ivan\source\repos\Задание1\Solver\VariantExercise.h"

using namespace miit::algebra;

void demonstrate_matrix_operations()
{
    std::cout << "=== Демонстрация операций с матрицей ===" << std::endl;

    // Создание и заполнение матрицы
    Matrix<int> mat(5);
    RandomGenerator gen(-100, 100);

    mat.fill(gen);
    std::cout << "Исходная матрица: " << mat.to_string() << std::endl;

    // Оператор сдвига влево
    Matrix<int> shifted_left = mat << 2;
    std::cout << "Сдвиг влево на 2: " << shifted_left.to_string() << std::endl;

    // Оператор сдвига вправо
    Matrix<int> shifted_right = mat >> 2;
    std::cout << "Сдвиг вправо на 2: " << shifted_right.to_string() << std::endl;

    // Оператор разыменования
    std::cout << "Первый элемент: " << *mat << std::endl;
}

void demonstrate_exercise()
{
    std::cout << "\n=== Демонстрация заданий варианта 14 ===" << std::endl;

    // Создание генератора и упражнения
    RandomGenerator gen(-100, 100);
    VariantExercise exercise(10, &gen, 999);

    // Заполнение матрицы
    exercise.fill_matrix();
    std::cout << "Исходная матрица: " << exercise.get_matrix().to_string() << std::endl;

    // Задание 1
    exercise.Task1();
    std::cout << "После Task1: " << exercise.get_matrix().to_string() << std::endl;

    // Задание 2
    exercise.Task2();
    std::cout << "После Task2 (K=" << exercise.get_K() << "): " << exercise.get_matrix().to_string() << std::endl;

    // Задание 3
    Matrix<int> P(8);
    RandomGenerator genP(1, 10);
    P.fill(genP);
    std::cout << "Массив P: " << P.to_string() << std::endl;

    Matrix<int> M = exercise.Task3(P);
    std::cout << "Массив M: " << M.to_string() << std::endl;
}

int main()
{
    try
    {
        demonstrate_matrix_operations();
        demonstrate_exercise();

        std::cout << "\n=== Демонстрация с вводом с клавиатуры ===" << std::endl;
        std::cout << "Введите 5 чисел для матрицы: ";

        IStreamGenerator stream_gen;
        VariantExercise manual_exercise(5, &stream_gen, 777);
        manual_exercise.fill_matrix();

        std::cout << "Матрица из ввода: " << manual_exercise.get_matrix().to_string() << std::endl;

        manual_exercise.Task1();
        std::cout << "После Task1: " << manual_exercise.get_matrix().to_string() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}