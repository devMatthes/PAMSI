#include <iostream>
#include <cstdlib>
#include <chrono>
#include <array>
#include <algorithm>

template <typename T, size_t N>
void quicksort(std::array<T, N>& numbers, const typename std::array<T, N>::iterator &p, const typename std::array<T, N>::iterator &q)
{
    auto pivot = *q;

    std::partition(numbers.begin(), numbers.end(), [&](int value) { return value < pivot; });
    auto s = std::partition_point(numbers.begin(), numbers.end(), [&](int value) { return value < pivot; });
    std::swap(*s, *q);
    if(p < q)
    {
        quicksort(numbers, p, s-1);
        quicksort(numbers, s+1, q);
    }
}

template <typename T, size_t N>
void display(std::array<T, N>& numbers)
{
    for(const auto& i : numbers)
    {
        std::cout << i << ' ';
    }
}

int main()
{
    std::array<int, 10> numbers;
    for(auto& i : numbers)
    {
        i = (std::rand() % 10000) + 6;
    }
    auto start = std::chrono::steady_clock::now();
    quicksort(numbers, numbers.begin(), (numbers.end() - 1));
    auto end = std::chrono::steady_clock::now();
    display(numbers);
    std::cout << std::endl;
    std::cout << "Czas w sekundach: " << std::chrono::duration_cast<std::chrono::seconds>(end-start).count() << std::endl;
    return 0;
}