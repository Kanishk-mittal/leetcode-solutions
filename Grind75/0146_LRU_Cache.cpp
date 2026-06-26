#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// we will nee a double circular linked list

class LRUCache
{
public:
    list<int> used_order;                                     // List to store the order of keys
    unordered_map<int, pair<int, list<int>::iterator>> cache; // Cache map with key -> (value, iterator in used_order)
    int capacity;

    LRUCache(int capacity) : capacity(capacity) {} // Correct constructor

    int get(int key)
    {
        if (cache.find(key) != cache.end())
        {
            // Move the accessed key to the front of the list (most recent use)
            used_order.erase(cache[key].second);
            used_order.push_front(key);
            cache[key].second = used_order.begin();

            return cache[key].first; // Return the value
        }
        return -1; // Return -1 if not found
    }

    void put(int key, int value)
    {
        if (cache.find(key) != cache.end())
        {
            // Key already exists, update the value and move to the front
            used_order.erase(cache[key].second);
        }
        else if (cache.size() >= capacity)
        {
            // Cache is full, remove the least recently used (LRU) key
            int lru_key = used_order.back();
            used_order.pop_back();
            cache.erase(lru_key);
        }

        // Insert the new key-value pair
        used_order.push_front(key);
        cache[key] = {value, used_order.begin()};
    }
};

int main()
{
    LRUCache sol(10);
    return 0;
}