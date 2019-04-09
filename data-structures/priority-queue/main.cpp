#include <iostream>
#include "queue.hh"
#include "element.hh"

int main()
{
    PriorityQueue<int> *base = new PriorityQueue<int>;
    base->enqueue(1,4);
    base->enqueue(4,2);
    base->enqueue(5,3);
    base->display();
    base->dequeue();
    base->display();
    base->dequeue();
    base->display();
    delete base;
    return 0;
}