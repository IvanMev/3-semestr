#include "Task1Exercise.h"

namespace miit::algebra
{
    Task1Exercise::Task1Exercise(size_t size, Generator* gen)
        : Exercise(size, gen)
    {
    }

    void Task1Exercise::SolveTask()
    {
        replaceLastMultipleOfThree();
    }

    void Task1Exercise::replaceLastMultipleOfThree()
    {
        int last_index = -1;
        auto& mat = get_matrix();
        for (size_t i = 0; i < mat.get_size(); ++i)
        {
            if (mat[i] % 3 == 0)
            {
                last_index = static_cast<int>(i);
            }
        }

        if (last_index != -1)
        {
            mat[last_index] = 0;
        }
    }
}