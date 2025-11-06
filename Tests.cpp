#include <iostream>
#include <cassert>
#include <vector>
#include "C:\Users\Ivan\source\repos\Задание1\Solver\Matrix.h"
#include "C:\Users\Ivan\source\repos\Задание1\Solver\RandomGenerator.h"
#include "C:\Users\Ivan\source\repos\Задание1\Solver\Task1Exercise.h"
#include "C:\Users\Ivan\source\repos\Задание1\Solver\Task2Exercise.h"
#include "C:\Users\Ivan\source\repos\Задание1\Solver\Task3Exercise.h"

using namespace miit::algebra;

class TestGenerator : public Generator
{
private:
    std::vector<int> values;
    mutable size_t current;

public:
    TestGenerator(const std::vector<int>& vals) : values(vals), current(0) {}

    int generate() const override
    {
        if (current >= values.size()) return 0;
        return values[current++];
    }
};

void test_task1_exercise()
{
    std::cout << "Test: Task1Exercise... ";
    TestGenerator gen({ 3, 6, 9, 12, 15 });
    Task1Exercise exercise(5, &gen);
    exercise.fill_matrix();

    exercise.SolveTask();
    Matrix<int> result = exercise.get_matrix();

    assert(result[4] == 0);
    std::cout << "PASS" << std::endl;
}

void test_task2_exercise()
{
    std::cout << "Test: Task2Exercise... ";
    TestGenerator gen({ 1, 2, 3, 4, 5 });
    Task2Exercise exercise(5, &gen, 999);
    exercise.fill_matrix();

    exercise.SolveTask();
    Matrix<int> result = exercise.get_matrix();

    assert(result[1] == 999);
    assert(result[3] == 999);
    std::cout << "PASS" << std::endl;
}

void test_task3_exercise()
{
    std::cout << "Test: Task3Exercise... ";
    Matrix<int> P(6);
    TestGenerator gen({ 1, 2, 3, 4, 5, 6 });
    P.fill(gen);

    Task3Exercise exercise(0, nullptr);
    Matrix<int> M = exercise.createArrayM(P);

    assert(M[0] == 0);
    assert(M[5] == 0);
    assert(M[3] == 16);
    assert(M[1] == 4);
    std::cout << "PASS" << std::endl;
}

void test_matrix_operations()
{
    std::cout << "Test: MatrixOperations... ";
    Matrix<int> mat(4);
    TestGenerator gen({ 1, 2, 3, 4 });
    mat.fill(gen);

    Matrix<int> left_shifted = mat << 1;
    assert(left_shifted[0] == 2);
    assert(left_shifted[1] == 3);
    assert(left_shifted[2] == 4);
    assert(left_shifted[3] == 1);

    Matrix<int> right_shifted = mat >> 1;
    assert(right_shifted[0] == 4);
    assert(right_shifted[1] == 1);
    assert(right_shifted[2] == 2);
    assert(right_shifted[3] == 3);
    std::cout << "PASS" << std::endl;
}

int main()
{
    try
    {
        std::cout << "=== Запуск модульных тестов ===" << std::endl;

        test_task1_exercise();
        test_task2_exercise();
        test_task3_exercise();
        test_matrix_operations();

        std::cout << "=== Все тесты успешно пройдены! ===" << std::endl;
        return 0;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Тест провален: " << e.what() << std::endl;
        return 1;
    }
}