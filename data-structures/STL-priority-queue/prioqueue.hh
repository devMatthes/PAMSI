#pragma once
#include <queue>

template <typename T>
class PriorityQueue
{
public:
std::priority_queue<T> nPrQueue;
    void enqueue(const T& newElement);
    T dequeue();
    void display();
    PriorityQueue() = default;
    ~PriorityQueue() = default;
};

template <typename T>
void PriorityQueue<T>::enqueue(const T& newElement)
{
    nPrQueue.push(newElement);
}

template <typename T>
T PriorityQueue<T>::dequeue()
{
    if(nPrQueue.empty())
    {
        std::cout << "Twoja kolejka jest pusta!" << std::endl;
    }
    else
    {
        nPrQueue.pop();
    }
    return 1;
}

template <typename T>
void PriorityQueue<T>::display()
{
    std::priority_queue<T> cpyPrQueue = nPrQueue;
    while(cpyPrQueue.empty() == false)
    {
        std::cout << cpyPrQueue.top() << " ";
        cpyPrQueue.pop();
    }
    std::cout << std::endl;
}