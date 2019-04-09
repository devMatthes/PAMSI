#include <iostream>
#include "prioqueue.hh"

int main()
{
    PriorityQueue<int> newQueue;
    newQueue.enqueue(3);
    newQueue.enqueue(1);
    newQueue.enqueue(2);
    newQueue.display();
    newQueue.dequeue();
    newQueue.display();
    return 0;
}