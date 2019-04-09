#include <iostream>
#include <cstdlib>
#include <chrono>
#include <array>

template <typename T, size_t N>
void bubble_sort(std::array<T, N>& numbers)
{
    for(unsigned int i=1; i<numbers.size(); i++)
    {
        for(unsigned int j=1; j<numbers.size(); j++)
        {
            if(numbers[j] < numbers[j-1])
            {
                std::swap(numbers[j-1], numbers[j]);
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
    std::array<int, 10> numbers;
    for(auto& i : numbers)
    {
        i = (std::rand() % 10000) + 6;
    }
    auto start = std::chrono::steady_clock::now();
    bubble_sort(numbers);
    auto end = std::chrono::steady_clock::now();
    display(numbers);
    std::cout << std::endl;
    std::cout << "Czas w sekundach: " << std::chrono::duration_cast<std::chrono::seconds>(end-start).count() << std::endl;
    return 0;
}