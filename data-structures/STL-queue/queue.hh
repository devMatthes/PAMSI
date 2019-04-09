#pragma once
#include <queue>

template <typename T>
class Queue
{
public:
    std::queue<T> nQueue;
    void enqueue(const T& newElement);
    T dequeue();
    void display();
    Queue() = default;
    ~Queue() = default;
};

template <typename T>
void Queue<T>::enqueue(const T& newElement)
{
    nQueue.push(newElement);
}

template <typename T>
T Queue<T>::dequeue()
{
    if(nQueue.empty())
    {
        std::cout << "Twoja kolejka jest pusta!" << std::endl;
    }
    else
    {
        nQueue.pop();
    }
    return 1;
}

template <typename T>
void Queue<T>::display()
{
    std::queue<T> cpyQueue = nQueue;
    while(cpyQueue.empty() == false)
    {
        std::cout << cpyQueue.front() << " ";
        cpyQueue.pop();
    }
    std::cout << std::endl;
}