#include "Exercise.h"

namespace miit::algebra
{
    Exercise::Exercise(size_t size, Generator* gen)
        : matrix(size), generator(gen) {
    }

    Matrix<int> Exercise::get_matrix() const
    {
        return matrix;
    }

    void Exercise::set_matrix(const Matrix<int>& new_matrix)
    {
        matrix = new_matrix;
    }

    void Exercise::fill_matrix()
    {
        matrix.fill(*generator);
    }
}