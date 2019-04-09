#pragma once
#include "element.hh"

template <typename T>
class PriorityQueue
{
    unsigned int counter;
    Element<T> *first;
public:
    void enqueue(const T& newElement, int priority);
    T dequeue();
    void display();
    PriorityQueue();
    ~PriorityQueue();
};

template <typename T>
PriorityQueue<T>::PriorityQueue() : first(nullptr), counter(0){}

template <typename T>
PriorityQueue<T>::~PriorityQueue()
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
void PriorityQueue<T>::enqueue(const T&newElement, int priority)
{
    Element<T> *newest = new Element<T>;
    newest->newElement = newElement;
    newest->priority = priority;
    if(first==nullptr || priority <= first->priority)
    {
        newest->next = first;
        first = newest;
        counter++;
    }
    else
    { 
        Element<T> *temp = first;
        if(temp->next !=nullptr && temp->next->priority <= priority)
        {
            temp = temp->next;
            temp->next = newest;
        }
        else
        {
            newest->next = temp->next;
            temp->next = newest;
            counter++;
        }    
    }
}

template <typename T>
T PriorityQueue<T>::dequeue()
{
    if(first==nullptr)
    {
        std::cout << "Twoja kolejka jest pusta!" << std::endl;
        return 0;
    }
    else
    {
        Element<T> *temp = first;
        first = first->next;
        delete temp;
        counter--;
    }
    return 1;
}

template <typename T>
void PriorityQueue<T>::display()
{
    Element<T> *temp = first;
    if(first==nullptr)
    {
        std::cout << "Twoja kolejka jest pusta!" << std::endl;
    }
    else
    {
        std::cout << "FIRST=> ";
        while(temp)
        {
            std::cout << temp->newElement << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
        std::cout << "Liczba elementow: " << counter << std::endl;
    }
}