#pragma once
#include "element.hh"

template <typename T>
class Stack
{
    unsigned int counter = 0;
    Element<T> *top;
public:
    Stack();
    ~Stack();
    void push(const T& newElement);
    T pop();
    void display();
};

template <typename T>
Stack<T>::Stack() : top(nullptr), counter(0){}

template <typename T>
Stack<T>::~Stack()
{
    Element<T> *curr = top;

    while(curr)
    {
        Element<T> *temp = top->next;
        delete temp;
        curr = temp;
    }

    top = nullptr;
}

template <typename T>
void Stack<T>::push(const T&newElement)
{
    Element<T> *newest = new Element<T>;
    newest->newElement = newElement;
    if(top==nullptr)
    {
        newest->next = nullptr;
        top = newest;
        counter++;
    }
    else
    { 
        newest->next = top;
        top = newest;
        counter++;
    }
}

template <typename T>
T Stack<T>::pop()
{
    if(top==nullptr)
    {
        std::cout << "Twoj stos jest pusty!" << std::endl;
        return 0;
    }
    else
    {
        Element<T> *temp = top;
        top = top->next;
        delete temp;
        counter--;
    }
    return 1;
}

template <typename T>
void Stack<T>::display()
{
    Element<T> *temp = top;
    std::cout << "TOP=> ";
    while(temp)
    {
        std::cout << temp->newElement << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
    std::cout << "Liczba elementow: " << counter << std::endl;
}