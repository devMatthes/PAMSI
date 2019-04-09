#include <iostream>
#include "stack.hh"

int main()
{
    Stack<int> newStack;
    newStack.push(1);
    newStack.push(2);
    newStack.display();
    newStack.pop();
    newStack.display();
    return 0;
}

