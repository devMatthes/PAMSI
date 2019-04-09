#include <array>
#include <iostream>
#include <stdlib.h>

template <std::size_t SIZE>
void merge(std::array<int, SIZE>& array, int leftIndex, int middleIndex, int rightIndex)
{
    std::array<int, array.size()> cpyArray;
    for(int i=leftIndex; i<=rightIndex; i++)
    {
        cpyArray[i] = array[i];
    }
    int point1 = leftIndex;
    int point2 = middleIndex;
    int current = leftIndex;

    while(point1 <= middleIndex && point2 <= rightIndex)
    {
        if(cpyArray[point1] <= cpyArray[point2])
        {
            array[current] = cpyArray[point1];
            point1++;
        }
        else
        {
            array[current] = cpyArray[point2];
            point2++;
        }
        current++;
    }
    while(point1 <= middleIndex)
    {
        array[current] = cpyArray[point1];
        current++; point1++;
    }
}

template <std::size_t SIZE>
void mergeSort(std::array<int, SIZE>& array, int leftIndex, int rightIndex)
{
    if(leftIndex < rightIndex)
    {
        int middle = (leftIndex + rightIndex) / 2;
        mergeSort(array, leftIndex, middle);
        mergeSort(array, middle + 1, rightIndex);
        merge(array, leftIndex, middle, rightIndex);
    }
}

template <std::size_t SIZE>
void sort(std::array<int, SIZE>& arrayToSort)
{
    mergeSort(arrayToSort, arrayToSort.front(), arrayToSort.back());
}

int main()
{
    std::array<int, 10> array;
    for(int i=0; i<array.size(); i++)
    {
        array[i] = rand() % 10 + 1;
    }
    std::cout << "Tablica przed posortowaniem:" << std::endl;
    for(const auto& s: array)
        std::cout << s << ' ';
    std::cout << std::endl;

    mergeSort(array, array.front(), array.back());
    std::cout << "Tablica po posortowaniu:" << std::endl;
    for(const auto& s: array)
        std::cout << s << ' ';
    std::cout << std::endl;
}
