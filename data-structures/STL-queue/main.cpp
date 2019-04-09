#include <iostream>
#include "queue.hh"

int main()
{
    Queue<int> newQueue;
    newQueue.enqueue(1);
    newQueue.enqueue(2);
    newQueue.display();
    newQueue.dequeue();
    newQueue.display();
    return 0;
}