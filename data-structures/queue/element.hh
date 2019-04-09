#pragma once

template <typename T>
struct Element
{
    T newElement;
    Element<T> *next, *prev;
    Element();
};

template <typename T>
Element<T>::Element()
{
    next = nullptr;
}