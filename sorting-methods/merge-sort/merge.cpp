#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cstdlib>

template <typename T>
void merge(std::vector<T>& arr, typename std::vector<T>::iterator begin, const typename std::vector<T>::iterator mid, const typename std::vector<T>::iterator end)
{
    std::vector<T> left(begin, mid);
    std::vector<T> right(mid, end);

    auto itL = left.begin();
    auto itR = right.begin();

    while(itL != left.end() && itR != right.end())
    {
        if(*itL <= *itR)
        {
            *begin = *itL;
            itL++;
        }
        else
        {
            *begin = *itR;
            itR++;
        }
        begin++;
    }

    std::copy(itL, left.end(), begin);
    std::copy(itR, right.end(), begin);
}

template <typename T>
void mergesort(std::vector<T>& arr, typename std::vector<T>::iterator begin,  const typename std::vector<T>::iterator end)
{
    auto middle = std::distance(begin, end) / 2;
    
    if(begin < (end-1))
    {
        auto mid = std::next(begin, middle);
        mergesort(arr, begin, mid);
        mergesort(arr, mid, end);
        merge(arr, begin, mid, end);
    }
}

template <typename T>
void display(std::vector<T> arr)
{
    for(auto& i : arr)
    {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> arr(5000);
    std::generate(arr.begin(), arr.end(), [](){return (std::rand() % 1000000) + 6;});
    std::cout << "Przed posortowaniem: ";
    //display(arr);
    auto start = std::chrono::steady_clock::now();
    mergesort(arr, arr.begin(), arr.end());
    auto end = std::chrono::steady_clock::now();
    //std::cout << "Po posortowaniu: ";
    //display(arr);
    std::cout << "Czas w sekundach: " << std::chrono::duration_cast<std::chrono::microseconds>(end-start).count() << std::endl;
    return 0;
}