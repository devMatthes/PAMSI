#pragma once

template <typename T>
struct Element
{
    T newElement;
    Element<T> *next;
    Element();
};

template <typename T>
Element<T>::Element()
{
    next = nullptr;
}