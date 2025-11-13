#include "Task2Exercise.h"

namespace miit::algebra
{
    Task2Exercise::Task2Exercise(size_t size, Generator* gen, int k)
        : Exercise(size, gen), K(k)
    {
    }

    void Task2Exercise::SolveTask()
    {
        insertKAfterEvenElements();
    }

    void Task2Exercise::insertKAfterEvenElements()
    {
        auto& mat = get_matrix();
        for (size_t i = 0; i < mat.get_size(); ++i)
        {
            if (mat[i] % 2 == 0)
            {
                mat[i] = K;
            }
        }
    }

    int Task2Exercise::get_K() const
    {
        return K;
    }

    void Task2Exercise::set_K(int k)
    {
        K = k;
    }
}