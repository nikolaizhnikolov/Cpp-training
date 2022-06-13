//#include "SortLib.h"
//template <typename T>
//void SortLib<T>::bubbleSort(std::vector<std::shared_ptr<T>> values)
//{
//    for (typename std::vector<std::shared_ptr<T>>::reverse_iterator it = (values.rbegin() + 1); it != values.rend(); it++)
//    {
//        for (typename std::vector<std::shared_ptr<T>>::iterator jt = values.begin(); jt != it.base(); jt++)
//        {
//            if (*(*jt) > *(*(jt + 1))) {
//                swap(*jt, *(jt + 1));
//            }
//        }
//    }
//    return;
//}
//
//template <typename T>
//void SortLib<T>::selectionSort(std::vector<std::shared_ptr<T>> values)
//{
//    maxSelectionSort(values);
//}
////template <typename T>
////void SortLib<T>::maxSelectionSort(std::vector<std::shared_ptr<T>> values)
////{
////    maxSelectionSort(values);
////}
////
////void SortLib::minSelectionSort(std::vector<std::shared_ptr<int>> values)
////{
////    for (std::vector<std::shared_ptr<int>>::iterator it = values.begin(); it != values.end(); it++)
////    {
////        std::shared_ptr<int> min = *it;
////        for (std::vector<std::shared_ptr<int>>::iterator jt = it; jt != values.end(); jt++)
////        {
////            if (*(*jt) < *(min)) {
////                min = *jt;
////            }
////        }
////        swap(min, *it);
////    }
////    return;
////}
////
////void SortLib::minSelectionSort(std::vector<std::shared_ptr<int>> values, bool reverse)
////{
////}
//
//template <typename T>
//void SortLib<T>::maxSelectionSort(std::vector<std::shared_ptr<T>> values)
//{
//    for (typename std::vector<std::shared_ptr<T>>::reverse_iterator it = values.rbegin(); it != values.rend(); it++)
//    {
//        std::shared_ptr<T> max = *it;
//        for (typename std::vector<std::shared_ptr<T>>::iterator jt = values.begin(); jt != it.base(); jt++)
//        {
//            if (booleanOperator(* (*jt), *(max))) {
//                max = *jt;
//            }
//        }
//        swap(max, *it);
//    }
//    return;
//}
//
//template <typename T>
//void SortLib<T>::swap(std::shared_ptr<T> a, std::shared_ptr<T> b)
//{
//    T c = *a;
//    *a = *b;
//    *b = c;
//}
