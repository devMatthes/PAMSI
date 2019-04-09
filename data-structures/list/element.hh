#pragma once

template <typename T>
struct Node
{
    T newElement;
    Node<T> *next, *prev;
    Node();
};

template <typename T>
Node<T>::Node()
{
    next = nullptr;
    prev = nullptr;
}