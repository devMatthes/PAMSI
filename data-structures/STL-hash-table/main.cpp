#include <iostream>
#include <string>
#include "hashtable.hh"

int main()
{
    HashTable<std::string, std::string> table;
    table.insert("BMW", "M5");
    table.insert("AUDI", "RS7");
    table.insert("Mercedes", "S63 AMG");
    table.insert("Audi", "RS5");
    table.insert("WMB", "M4");
    table.display();
    std::cout << "%%%%%%%%%%%" << std::endl;
    table("BMW") = "7";
    table.display();
    table.remove("AUDI");
    std::cout << "%%%%%%%%%%%" << std::endl;
    table.display();
    return 0;
}