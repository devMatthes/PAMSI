#include <array>
#include <chrono>
#include <algorithm>
#include <iostream>
#include <cstdlib>

template <typename T, size_t N>
void merge(std::array<T, N>& array, const typename std::array<T, N>::iterator &left, const typename std::array<T, N>::iterator &middle, const typename std::array<T, N>::iterator &right)
{
    std::array<T, N> cpyArray;
    auto f1 = left;
    auto f2 = middle;
    auto current = left;

    while(f1 < middle && f2 < right)
    {
        if(array[*f1] < array[*f2])
        {
            cpyArray[*current] = array[*f1];
            std::advance(f1, 1);
        }
        else
        {
            cpyArray[*current] = array[*f2];
            std::advance(f2, 1);
        }
        std::advance(current, 1);
    }
    while(f1 < middle)
    {
        cpyArray[*current] = array[*f1];
        std::advance(f1, 1);
        std::advance(current, 1);
    }
    std::copy(cpyArray.begin(), cpyArray.end(), array.begin());
}

template <typename T, size_t N>
void mergesort(std::array<T, N>& array, const typename std::array<T, N>::iterator &left, const typename std::array<T, N>::iterator &right)
{
    if(left < right)
    {
        auto middle = array.begin() + array.size() / 2;
        mergesort(array, left, middle);
        mergesort(array, middle, right);
        merge(array, left, middle, right);
    }
}

int main()
{
    std::array<int, 10> array;
    for(unsigned int i=0; i<array.size(); i++)
    {
        array[i] = rand() % 10 + 1;
    }

    std::cout << "Tablica przed posortowaniem:" << std::endl;
    for(const auto& s: array)
    {
        std::cout << s << ' ';
    }
    std::cout << std::endl;

    mergesort(array, array.begin(), (array.end() - 1));
    std::cout << "Tablica po posortowaniu:" << std::endl;
    for(const auto& s: array)
    {
        std::cout << s << ' ';
    }
    std::cout << std::endl;
}
