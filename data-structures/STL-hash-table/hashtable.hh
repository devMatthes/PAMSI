#pragma once
#include <map>

template <typename KeyType, typename ValueType>
class HashTable
{
    struct Element
    {
        KeyType key;
        ValueType value;
    };

    std::map<KeyType, ValueType> map1;
public:
    void insert(const KeyType& key, const ValueType& value);
    ValueType& operator()(const KeyType& key);
    void remove(const KeyType& key);
    void display();
    HashTable() = default;
    ~HashTable() = default;
};

template <typename KeyType, typename ValueType>
void HashTable<KeyType, ValueType>::insert(const KeyType& key, const ValueType& value)
{
    map1.insert({key, value});
}

template <typename KeyType, typename ValueType>
ValueType& HashTable<KeyType, ValueType>::operator()(const KeyType& key)
{
    return map1[key];
}

template <typename KeyType, typename ValueType>
void HashTable<KeyType, ValueType>::remove(const KeyType& key)
{
    map1.erase(key);
}

template <typename KeyType, typename ValueType>
void HashTable<KeyType, ValueType>::display() 
{ 
    for(auto it = map1.begin(); it != map1.end(); it++)
    {
        std::cout << it->first << " " << it->second << std::endl;
    }
} 