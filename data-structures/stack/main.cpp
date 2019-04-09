#include <iostream>
#include "stack.hh"
#include "element.hh"

int main()
{
    Stack<int> *base = new Stack<int>;
    base->push(5);
    base->push(5);
    base->push(3);
    base->push(4);
    base->display();
    base->pop();
    base->display();
    delete base;
    return 0;
}

