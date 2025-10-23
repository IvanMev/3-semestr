#include <iostream>
#include <cassert>
#include <vector>
#include "Matrix.h"
#include "RandomGenerator.h"
#include "VariantExercise.h"

using namespace miit::algebra;

class TestGenerator : public Generator
{
private:
    std::vector<int> values;
    size_t current;

public:
    TestGenerator(const std::vector<int>& vals) : values(vals), current(0) {}

    int generate() override
    {
        if (current >= values.size()) return 0;
        return values[current++];
    }
};

void test_default_constructor()
{
    std::cout << "Test: DefaultConstructor... ";
    Matrix<int> mat;
    assert(mat.get_size() == 0);
    std::cout << "PASS" << std::endl;
}

void test_size_constructor()
{
    std::cout << "Test: SizeConstructor... ";
    Matrix<int> mat(5);
    assert(mat.get_size() == 5);
    std::cout << "PASS" << std::endl;
}

void test_copy_constructor()
{
    std::cout << "Test: CopyConstructor... ";
    Matrix<int> mat1(3);
    TestGenerator gen({ 1, 2, 3 });
    mat1.fill(gen);

    Matrix<int> mat2(mat1);
    assert(mat2.get_size() == 3);
    assert(mat2[0] == 1);
    assert(mat2[1] == 2);
    assert(mat2[2] == 3);
    std::cout << "PASS" << std::endl;
}

void test_assignment_operator()
{
    std::cout << "Test: AssignmentOperator... ";
    Matrix<int> mat1(2);
    TestGenerator gen({ 10, 20 });
    mat1.fill(gen);

    Matrix<int> mat2;
    mat2 = mat1;
    assert(mat2.get_size() == 2);
    assert(mat2[0] == 10);
    assert(mat2[1] == 20);
    std::cout << "PASS" << std::endl;
}

void test_task1()
{
    std::cout << "Test: Task1Test... ";
    TestGenerator gen({ 3, 6, 9, 12, 15 });
    VariantExercise exercise(5, &gen);
    exercise.fill_matrix();

    exercise.Task1();
    Matrix<int> result = exercise.get_matrix();

    assert(result[4] == 0);  // Последний кратный 3 должен быть заменен на 0
    std::cout << "PASS" << std::endl;
}

void test_task3()
{
    std::cout << "Test: Task3Test... ";
    Matrix<int> P(6);
    TestGenerator gen({ 1, 2, 3, 4, 5, 6 });
    P.fill(gen);

    VariantExercise exercise(0, nullptr);
    Matrix<int> M = exercise.Task3(P);

    assert(M[0] == 0);      // Первый элемент
    assert(M[5] == 0);      // Последний элемент
    assert(M[3] == 16);     // 4 * abs(4) = 16 (четвертый элемент)
    assert(M[1] == 4);      // 2 * (1+1) = 4
    std::cout << "PASS" << std::endl;
}

void test_shift_operators()
{
    std::cout << "Test: ShiftOperators... ";
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

        test_default_constructor();
        test_size_constructor();
        test_copy_constructor();
        test_assignment_operator();
        test_shift_operators();
        test_task1();
        test_task3();

        std::cout << "=== Все тесты успешно пройдены! ===" << std::endl;
        return 0;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Тест провален: " << e.what() << std::endl;
        return 1;
    }
    catch (...)
    {
        std::cerr << "Неизвестная ошибка в тесте" << std::endl;
        return 1;
    }
}