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

//void SortLib::selectionSort(std::vector<std::shared_ptr<int>> values)
//{
//    maxSelectionSort(values);
//}

void SortLib::minSelectionSort(std::vector<std::shared_ptr<int>> values)
{
    for (std::vector<std::shared_ptr<int>>::iterator it = values.begin(); it != values.end(); it++)
    {
        std::shared_ptr<int> min = *it;
        for (std::vector<std::shared_ptr<int>>::iterator jt = it; jt != values.end(); jt++)
        {
            if (*(*jt) < *(min)) {
                min = *jt;
            }
        }
        swap(min, *it);
    }
    return;
}

void SortLib::maxSelectionSort(std::vector<std::shared_ptr<int>> values)
{
    for (std::vector<std::shared_ptr<int>>::reverse_iterator it = values.rbegin(); it != values.rend(); it++)
    {
        std::shared_ptr<int> max = *it;
        for (std::vector<std::shared_ptr<int>>::iterator jt = values.begin(); jt != it.base(); jt++)
        {
            if (*(*jt) > *(max)) {
                max = *jt;
            }
        }
        swap(max, *it);
    }
    return;
}


void SortLib::swap(std::shared_ptr<int> a, std::shared_ptr<int> b)
{
    int c = *a;
    *a = *b;
    *b = c;
}
