#include <iostream>
#include "queue.hh"
#include "element.hh"

int main()
{
    Queue<int> *base = new Queue<int>;
    base->enqueue(5);
    base->enqueue(2);
    base->enqueue(4);
    base->display();
    base->dequeue();
    base->display();
    delete base;
    return 0;
}