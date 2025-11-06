#include "Task3Exercise.h"
#include <cmath>

namespace miit::algebra
{
    Task3Exercise::Task3Exercise(size_t size, Generator* gen)
        : Exercise(size, gen)
    {
    }

    void Task3Exercise::SolveTask()
    {
        // Для Task3 требуется внешний массив P, поэтому оставляем пустым
    }

    Matrix<int> Task3Exercise::createArrayM(const Matrix<int>& P)
    {
        Matrix<int> M(P.get_size());
        for (size_t i = 0; i < P.get_size(); ++i)
        {
            if (i == 0 || i == P.get_size() - 1)
            {
                M[i] = 0;
            }
            else if (P[i] % 2 == 0)
            {
                M[i] = P[i] * std::abs(P[i]);
            }
            else
            {
                M[i] = P[i] * (static_cast<int>(i) + 1);
            }
        }
        return M;
    }
}