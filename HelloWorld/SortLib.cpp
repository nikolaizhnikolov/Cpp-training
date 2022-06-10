#include "SortLib.h"

void SortLib::bubbleSort(std::vector<std::shared_ptr<int>> values)
{
    for (std::vector<std::shared_ptr<int>>::reverse_iterator it = (values.rbegin() + 1); it != values.rend(); it++)
    {
        for (std::vector<std::shared_ptr<int>>::iterator jt = values.begin(); jt != it.base(); jt++)
        {
            if (*(*jt) > *(*(jt + 1))) {
                swap(*jt, *(jt + 1));
            }
        }
    }
    return;
}

void SortLib::swap(std::shared_ptr<int> a, std::shared_ptr<int> b)
{
    int c = *a;
    *a = *b;
    *b = c;
}
