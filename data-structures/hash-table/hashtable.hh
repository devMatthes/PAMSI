#pragma once

template <typename KeyType, typename ValueType>
class HashTable
{
    static const int size = 10;
    
    struct Element
    {
        KeyType key;
        ValueType value;
    };

    Element* bucket[size];
public:
    void insert(const KeyType& key, const ValueType& value);
    ValueType& operator()(const KeyType& key);
    void remove(const KeyType& key);
    void display();
    HashTable();
    ~HashTable();
};

template <typename KeyType, typename ValueType>
HashTable<KeyType, ValueType>::HashTable()
{
    for(int i=0; i<size; i++)
    {
        bucket[i] = new Element;
        bucket[i]->key = "null";
        bucket[i]->value = "null";
    }
}

template <typename KeyType, typename ValueType>
HashTable<KeyType, ValueType>::~HashTable(){}

template <typename KeyType, typename ValueType>
void HashTable<KeyType, ValueType>::insert(const KeyType& key, const ValueType& value)
{
    int hashIndex, hashCode = 0;

    for(int i=0; i<key.length(); i++)
    {
        hashCode = hashCode + (int)key[i];
    }

    hashIndex = hashCode % size;

    bucket[hashIndex]->key = key;
    bucket[hashIndex]->value = value;
}

template <typename KeyType, typename ValueType>
ValueType& HashTable<KeyType, ValueType>::operator()(const KeyType& key)
{
    int hashIndex, hashCode = 0;

    for(int i=0; i<key.length(); i++)
    {
        hashCode = hashCode + (int)key[i];
    }

    hashIndex = hashCode % size;

    return bucket[hashIndex]->value;
}

template <typename KeyType, typename ValueType>
void HashTable<KeyType, ValueType>::remove(const KeyType& key)
{
    int hashIndex, hashCode = 0;

    for(int i=0; i<key.length(); i++)
    {
        hashCode = hashCode + (int)key[i];
    }

    hashIndex = hashCode % size;

    bucket[hashIndex]->key = "null";
    bucket[hashIndex]->value = "null";
}

template <typename KeyType, typename ValueType>
void HashTable<KeyType, ValueType>::display() 
{ 
    for(int i=0; i<size; i++) 
    { 
        std::cout << bucket[i]->key << std::endl;
        std::cout << bucket[i]->value << std::endl;
        std::cout << "------------" << std::endl;
    } 
} 