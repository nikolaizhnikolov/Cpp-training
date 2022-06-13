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
    static void sort(std::vector<std::shared_ptr<T>> values)
    {
        selectionSort(values, false);
    }

    static void bubbleSort(std::vector<std::shared_ptr<T>> values)
    {
        bubbleSort(values, false);
    }
    static void bubbleSort(std::vector<std::shared_ptr<T>> values, bool reverse)
    {
        if (reverse)
            bubbleSort(values, std::less<T>());
        else
            bubbleSort(values, std::greater<T>());
    }

    static void selectionSort(std::vector<std::shared_ptr<T>> values)
    {
        selectionSort(values, false);
    }
    static void selectionSort(std::vector<std::shared_ptr<T>> values, bool reverse)
    {
        if(reverse)
            selectionSort(values, std::less<T>());
        else
            selectionSort(values, std::greater<T>());
    }

    static void insertionSort(std::vector<std::shared_ptr<T>> values)
    {
        insertionSort(values, false);
    }
    static void insertionSort(std::vector<std::shared_ptr<T>> values, bool reverse)
    {
        if(reverse)
            insertionSort(values, std::less<T>());
        else
            insertionSort(values, std::greater<T>());
    }

private:
    static void swap(std::shared_ptr<T> a, std::shared_ptr<T> b)
    {
        T c = *a;
        *a = *b;
        *b = c;
    }

    static void bubbleSort(std::vector<std::shared_ptr<T>> values, std::function<bool(T, T)> comparator)
    {
        for (typename std::vector<std::shared_ptr<T>>::reverse_iterator it = (values.rbegin() + 1); it != values.rend(); it++)
        {
            for (typename std::vector<std::shared_ptr<T>>::iterator jt = values.begin(); jt != it.base(); jt++)
            {
                if (comparator (* (*jt), *(*(jt + 1)))) {
                    swap(*jt, *(jt + 1));
                }
            }
        }
    }

    static void selectionSort(std::vector<std::shared_ptr<T>> values, std::function<bool(T, T)> comparator)
    {
        for (typename std::vector<std::shared_ptr<T>>::reverse_iterator it = values.rbegin(); it != values.rend(); it++)
        {
            std::shared_ptr<T> max = *it;
            for (typename std::vector<std::shared_ptr<T>>::iterator jt = values.begin(); jt != it.base(); jt++)
            {
                if (comparator(*(*jt), *(max))) {
                    max = *jt;
                }
            }
            swap(max, *it);
        }
        return;
    }

    static void insertionSort(std::vector<std::shared_ptr<T>> values, std::function<bool(T, T)> comparator)
    {
        int counter = 0;
        for (typename std::vector<std::shared_ptr<T>>::iterator it = std::next(values.begin() + counter); it != values.end(); it++, counter++)
        {
            T key = *(*it);
            typename std::vector<std::shared_ptr<T>>::iterator jt = std::next(values.begin() + counter);
            while (jt != values.begin() && comparator( *(*(jt - 1)), key))
            {
                *(*jt) = *(*(jt - 1));
                jt--;
            }
            *(*(jt)) = key;
        }
    }
};

