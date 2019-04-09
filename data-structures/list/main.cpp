#include <iostream>
#include "list.hh"
#include "element.hh"

int main()
{
    List<int> *base = new List<int>;
    base->pushBack(2);
    base->pushBack(3);
    base->display();
    base->pushFront(1);
    base->display();
    base->insert(4,4);
    base->display();
    base->remove(3);
    base->display();
    delete base;
    return 0;
}

