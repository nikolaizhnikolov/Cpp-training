#pragma once

#include <vector>
#include <iostream>
#include <functional>


template <typename T>
class SortLib
{
	//TODO: choose default sorting algorithm as sort()
	// add reverse sorting option for all algos
	// to handl reverse sorting add delegation to private sorting methods with
	//	 operators passed in as parameters
	//	 handle objects other than integers
	//   handle other types of pointers
    // 

public:
    static void bubbleSort(std::vector<std::shared_ptr<T>> values)
    {
        for (typename std::vector<std::shared_ptr<T>>::reverse_iterator it = (values.rbegin() + 1); it != values.rend(); it++)
        {
            for (typename std::vector<std::shared_ptr<T>>::iterator jt = values.begin(); jt != it.base(); jt++)
            {
                if (*(*jt) > *(*(jt + 1))) {
                    swap(*jt, *(jt + 1));
                }
            }
        }
    }

    static void selectionSort(std::vector<std::shared_ptr<T>> values)
    {
        maxSelectionSort(values, std::less<T>());
    }

    static void maxSelectionSort(std::vector<std::shared_ptr<T>> values, std::function<bool(T,T)> f)
    {
        for (typename std::vector<std::shared_ptr<T>>::reverse_iterator it = values.rbegin(); it != values.rend(); it++)
        {
            std::shared_ptr<T> max = *it;
            for (typename std::vector<std::shared_ptr<T>>::iterator jt = values.begin(); jt != it.base(); jt++)
            {
                if (f(* (*jt), *(max))) {
                    max = *jt;
                }
            }
            swap(max, *it);
        }
        return;
    }

private:
    static void swap(std::shared_ptr<T> a, std::shared_ptr<T> b)
    {
        T c = *a;
        *a = *b;
        *b = c;
    }

};

