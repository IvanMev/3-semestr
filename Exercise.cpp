#include "Exercise.h"

namespace miit::algebra
{
    Exercise::Exercise(size_t size, Generator* gen)
        : matrix(size), generator(gen) {
        if (gen != nullptr && size > 0) {
            fill_matrix();
        }
    }

    void Exercise::fill_matrix()
    {
        matrix.fill(*generator);
    }
}