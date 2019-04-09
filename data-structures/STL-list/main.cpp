#include <iostream>
#include <list>
#include "list.hh"


int main()
{
    List<int> newList;
    newList.pushBack(2);
    newList.display();
    newList.pushFront(1);
    newList.display();
    newList.insert(4,2);
    newList.display();
    newList.remove(2);
    newList.display();
    std::cout << newList[2] << std::endl;
    return 0;
}

