#include <iostream>
#include <cstdlib>
#include <chrono>
#include <array>

template <typename T, size_t N>
void bubble_sort(std::array<T, N>& numbers)
{
    for(const auto& i : numbers)
    //for(unsigned int i = 1; i<numbers.size(); i++)
    {
        for(typename std::array<T, N>::iterator it = numbers.begin(); it != numbers.end(); it++)
        {
            if(*it < *(it - 1))
            {
                std::swap(*it, *(it - 1));
            }
        }
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
    std::array<int, 5000> numbers;
    for(auto& i : numbers)
    {
        i = std::rand() % 200000;
    }
    auto start = std::chrono::steady_clock::now();
    bubble_sort(numbers);
    auto end = std::chrono::steady_clock::now();
    //display(numbers);
    std::cout << std::endl;
    std::cout << "Czas w sekundach: " << std::chrono::duration_cast<std::chrono::microseconds>(end-start).count() << std::endl;
    return 0;
}