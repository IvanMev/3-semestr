#include "Exercise.h"

namespace miit::algebra
{
    Exercise::Exercise(size_t size, Generator* gen)
        : matrix(size), generator(gen) {
        if (gen != nullptr && size > 0) {
            matrix.fill(*generator);
        }
    }
}