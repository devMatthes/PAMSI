#pragma once
#include "element.hh"

template <typename T>
class Queue
{
    unsigned int counter;
    Element<T> *first, *last;
public:
    void enqueue(const T& newElement);
    T dequeue();
    void display();
    Queue();
    ~Queue();
};

template <typename T>
Queue<T>::Queue() : first(nullptr), last(nullptr), counter(0){}

template <typename T>
Queue<T>::~Queue()
{
    Element<T> *curr = first;
    while(curr)
    {
        Element<T> *temp = first->next;
        delete temp;
        curr = temp;
    }
}

template <typename T>
void Queue<T>::enqueue(const T&newElement)
{
    Element<T> *newest = new Element<T>;
    newest->newElement = newElement;
    if(first==nullptr)
    {
        newest->prev = nullptr;
        newest->next = nullptr;
        first = newest;
        last = newest;
        counter++;
    }
    else
    { 
        Element<T> *temp = last;
        last = newest;
        last->next = temp;
        temp->prev = last;
        counter++;
    }
}

template <typename T>
T Queue<T>::dequeue()
{
    if(first==nullptr)
    {
        std::cout << "Twoja kolejka jest pusta!" << std::endl;
        return 0;
    }
    else
    {
        Element<T> *temp = first;
        first = first->prev;
        first->next = nullptr;
        delete temp;
        counter--;
    }
    return 1;
}

template <typename T>
void Queue<T>::display()
{
    Element<T> *temp = last;
    std::cout << "LAST=> ";
    while(temp)
    {
        std::cout << temp->newElement << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
    std::cout << "Liczba elementow: " << counter << std::endl;
}