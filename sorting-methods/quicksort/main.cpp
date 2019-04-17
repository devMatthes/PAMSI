#include <iostream>
#include <cstdlib>
#include <chrono>
#include <array>
#include <algorithm>
#include <random>

template <typename T>
void quicksort(std::vector<T>& numbers, typename std::vector<T>::iterator p, typename std::vector<T>::iterator q)
{
    if(p >= q)
    {
        return;
    }
    auto pivot = q;
    auto border = std::partition(p, q, [pivot](const auto& value){ return value < *pivot; });

    if(border != q)
    {
        std::swap(*border, *q);
    }

    quicksort(numbers, p, border - 1);
    quicksort(numbers, border + 1, q);
}

template <typename T>
void display(std::vector<T>& numbers)
{
    for(const auto& i : numbers)
    {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> numbers(5000);
    std::generate(numbers.begin(), numbers.end(), [](){return std::rand() % 5000;});
    //display(numbers);
    auto start = std::chrono::steady_clock::now();
    quicksort(numbers, numbers.begin(), (numbers.end()-1));
    auto end = std::chrono::steady_clock::now();
    //display(numbers);
    std::cout << std::endl;
    std::cout << "Czas w sekundach: " << std::chrono::duration_cast<std::chrono::microseconds>(end-start).count() << std::endl;
    return 0;
}