#pragma once
#include <list>


template <typename T>
class List
{
    struct Iterator
    {
        Iterator() = default;
        ~Iterator();
    };
    struct ConstIterator
    {
        ConstIterator() = default;
        ~ConstIterator();
    };
public:
    std::list<T> lista;
    unsigned int counter = 0;
    void pushBack(const T& newElement);
    void pushFront(const T& newElement);
    void insert(const T& newElement, int index);
    void remove(const T& newElement);
    void display();
    Iterator begin();
    Iterator end();
    ConstIterator cbegin() const;
    ConstIterator cend() const;
    T& operator[](int index);
    List() = default;
    ~List(){}
};

template <typename T>
T& List<T>::operator[](int index)
{
    auto it = lista.begin();
    std::advance(it, (index-1));
    return *it;
}

template <typename T>
void List<T>::pushBack(const T& newElement)
{
    lista.push_back(newElement);
    counter++;
}

template <typename T>
void List<T>::pushFront(const T& newElement)
{
    lista.push_front(newElement);
    counter++;
}

template <typename T>
void List<T>::insert(const T&newElement, int index)
{
    if(index<=0)
    {
        std::cout << "Nie mozna wprowadzic elementu na wybrana pozycje!" << std::endl;
    }
    else if(index==1)
    {
        lista.push_front(newElement);
        counter++;
    }
    else if(index<=counter && index>1)
    {
        auto it = lista.begin();
        std::advance(it, (index-1));
        lista.insert(it, newElement);
        counter++;
    }
    else if(index>counter)
    {
        lista.push_back(newElement);
        counter++;
    }
}

template <typename T>
void List<T>::remove(const T& newElement)
{
    lista.remove(newElement);
    counter--;
}

template <typename T>
void List<T>::display()
{
    auto it = lista.begin();
    for(it; it!=lista.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

template <typename T>
typename List<T>::Iterator List<T>::begin()
{
    auto it = lista.begin();
    return it;
}

template <typename T>
typename List<T>::Iterator List<T>::end()
{
    auto it = lista.end();
    return it;
}

template <typename T>
typename List<T>::ConstIterator List<T>::cbegin() const
{
    auto it = lista.begin();
    return it;
}

template <typename T>
typename List<T>::ConstIterator List<T>::cend() const
{
    auto it = lista.end();
    return it;
}