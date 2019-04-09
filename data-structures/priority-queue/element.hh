#pragma once

template <typename T>
struct Element
{
    T newElement;
    int priority;
    Element<T> *next, *prev;
    Element();
};

template <typename T>
Element<T>::Element()
{
    next = nullptr;
    prev = nullptr;
}