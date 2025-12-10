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

void test_task1_basic()
{
    TestGenerator gen({ 3, 6, 9, 12, 15 });
    Task1Exercise exercise(5, &gen);
    exercise.SolveTask();

    Matrix<int> result = exercise.matrix;
    assert(result[4] == 0); 
    std::cout << "PASS" << std::endl;
}

void test_task1_no_multiple_of_three()
{
    TestGenerator gen({ 1, 2, 4, 5, 7 });
    Task1Exercise exercise(5, &gen);
    exercise.SolveTask();

    Matrix<int> result = exercise.matrix;
    assert(result[0] == 1);
    assert(result[1] == 2);
    assert(result[2] == 4);
    assert(result[3] == 5);
    assert(result[4] == 7);
    std::cout << "PASS" << std::endl;
}

void test_task1_multiple_at_different_positions()
{
    TestGenerator gen({ 1, 3, 2, 6, 4 });
    Task1Exercise exercise(5, &gen);
    exercise.SolveTask();

    Matrix<int> result = exercise.matrix;
    assert(result[3] == 0); 
    std::cout << "PASS" << std::endl;
}

void test_task2_basic()
{
    TestGenerator gen({ 1, 2, 3, 4, 5 });
    Task2Exercise exercise(5, &gen, 999);
    exercise.SolveTask();

    Matrix<int> result = exercise.matrix;
    assert(result[1] == 999); 
    assert(result[3] == 999); 
    assert(result[0] == 1);   
    assert(result[2] == 3);   
    assert(result[4] == 5);   
    std::cout << "PASS" << std::endl;
}

void test_task2_no_even_elements()
{
    TestGenerator gen({ 1, 3, 5, 7, 9 });
    Task2Exercise exercise(5, &gen, 999);
    exercise.SolveTask();

    Matrix<int> result = exercise.matrix;
    assert(result[0] == 1);
    assert(result[1] == 3);
    assert(result[2] == 5);
    assert(result[3] == 7);
    assert(result[4] == 9);
    std::cout << "PASS" << std::endl;
}

void test_task2_all_even_elements()
{
    TestGenerator gen({ 2, 4, 6, 8, 10 });
    Task2Exercise exercise(5, &gen, 777);
    exercise.SolveTask();

    Matrix<int> result = exercise.matrix;
    assert(result[0] == 777);
    assert(result[1] == 777);
    assert(result[2] == 777);
    assert(result[3] == 777);
    assert(result[4] == 777);
    std::cout << "PASS" << std::endl;
}

void test_task3_basic()
{
    std::cout << "Test: Task3 Basic... ";
    Matrix<int> P(6);
    TestGenerator gen({ 1, 2, 3, 4, 5, 6 });
    P.fill(gen);

    Task3Exercise exercise(0);
    Matrix<int> M = exercise.createArrayM(P);

    assert(M[0] == 0);  
    assert(M[5] == 0);   
    assert(M[1] == 4); 
    assert(M[2] == 9);  
    assert(M[3] == 16); 
    assert(M[4] == 25);  
    std::cout << "PASS" << std::endl;
}

void test_task3_small_array()
{

    Matrix<int> P(2);
    TestGenerator gen({ 1, 2 });
    P.fill(gen);

    Task3Exercise exercise(0);
    Matrix<int> M = exercise.createArrayM(P);

    assert(M[0] == 0);   
    assert(M[1] == 0);   
    std::cout << "PASS" << std::endl;
}

void test_task3_single_element()
{
    Matrix<int> P(1);
    TestGenerator gen({ 5 });
    P.fill(gen);

    Task3Exercise exercise(0);
    Matrix<int> M = exercise.createArrayM(P);

    assert(M[0] == 0); 
    std::cout << "PASS" << std::endl;
}

void test_matrix_operations()
{
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

void test_matrix_creation_and_access()
{
    Matrix<int> mat(3);
    TestGenerator gen({ 10, 20, 30 });
    mat.fill(gen);

    assert(mat.get_size() == 3);
    assert(mat[0] == 10);
    assert(mat[1] == 20);
    assert(mat[2] == 30);

    mat[1] = 25;
    assert(mat[1] == 25);
    std::cout << "PASS" << std::endl;
}

void test_matrix_string_conversion()
{
    Matrix<int> mat(3);
    TestGenerator gen({ 1, 2, 3 });
    mat.fill(gen);

    std::string str = mat.to_string();
    assert(str == "[1, 2, 3]");
    std::cout << "PASS" << std::endl;
}

void test_matrix_resize()
{
    Matrix<int> mat(3);
    TestGenerator gen({ 1, 2, 3 });
    mat.fill(gen);

    mat.resize(5);
    assert(mat.get_size() == 5);

    mat.resize(2);
    assert(mat.get_size() == 2);
    std::cout << "PASS" << std::endl;
}


int main()
{
        test_task1_basic();
        test_task1_no_multiple_of_three();
        test_task1_multiple_at_different_positions();

        test_task2_basic();
        test_task2_no_even_elements();
        test_task2_all_even_elements();

        test_task3_basic();
        test_task3_small_array();
        test_task3_single_element();

        test_matrix_operations();
        test_matrix_creation_and_access();
        test_matrix_string_conversion();
        test_matrix_resize();

        return 0;
}