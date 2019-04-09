#pragma once
#include <stack>

template <typename T>
class Stack
{
public:
    std::stack <T> stos;
    unsigned int counter = 0;
    void push(const T& newElement);
    T pop();
    void display();
    Stack() = default;
    ~Stack() = default;
};

template <typename T>
void Stack<T>::push(const T& newElement)
{
    stos.push(newElement);
    counter++;
}

template <typename T>
T Stack<T>::pop()
{
    if(stos.empty())
    {
        std::cout << "Twoj stos jest pusty!" << std::endl;
        return 0;
    }
    else
    {
        stos.pop();
        counter--;
    }
    return 1;
}

template <typename T>
void Stack<T>::display()
{
    std::stack<T> cpyStack = stos;
    for(cpyStack; !cpyStack.empty(); cpyStack.pop())
    {
        std::cout << cpyStack.top() << std::endl;
    }
}