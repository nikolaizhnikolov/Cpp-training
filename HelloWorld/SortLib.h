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

    static void mergeSort(std::vector<std::shared_ptr<T>> values)
    {
        mergeSort(values, false);
    }
    static void mergeSort(std::vector<std::shared_ptr<T>> values, bool reverse)
    {
        if (reverse)
            mergeSort(values, 0, values.size() - 1, std::less<T>());
        else
            mergeSort(values, 0, values.size() - 1, std::greater<T>());
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

    static void mergeSort(std::vector<std::shared_ptr<T>> values, int start, int end, std::function<bool(T, T)> comparator)
    {
        if (start >= end) return;
        int mid = (start + end) / 2;
        mergeSort(values, start, mid, comparator);
        mergeSort(values, mid + 1, end, comparator);
        merge(values, start, mid, end);
    }

    static void merge(std::vector<std::shared_ptr<T>> values, int start, int mid, int end)
    {
        std::vector<int> v1;
        std::vector<int> v2;
        for (int i = start; i <= mid; i++)
            v1.push_back(*values[i]);
        for (int i = mid + 1; i <= end; i++)
            v2.push_back(*values[i]);

        int i, j, k;
        for (i = 0, j = 0, k = start; i < v1.size() && j < v2.size(); k++) {
            if (v1.at(i) <= v2.at(j)) {
                *values.at(k) = v1.at(i);
                i++;
            }
            else if (v1.at(i) > v2.at(j)) {
                *values.at(k) = v2.at(j);
                j++;
            }
        }

        while (i < v1.size()) {
            *values.at(k) = v1.at(i);
            i++;
            k++;
        }

        while (j < v2.size()) {
            *values.at(k) = v2.at(j);
            j++;
            k++;
        }
        
    }
};

