#include <iostream>
#include <vector>
#include <unordered_set>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()

class RandomizedSet
{
private:
    std::vector<int> data;       // To store the elements
    std::unordered_set<int> set; // To check existence of elements for O(1) insertion and deletion

public:
    // Constructor
    RandomizedSet()
    {
        srand(time(0)); // Initialize random seed
    }

    // Inserts a value. Returns true if inserted, false if the value already exists.
    bool insert(int val)
    {
        if (set.find(val) == set.end())
        {
            data.push_back(val); // Add value to the vector
            set.insert(val);     // Add value to the set
            return true;
        }
        return false;
    }

    // Removes a value. Returns true if removed, false if the value doesn't exist.
    bool remove(int val)
    {
        if (set.find(val) != set.end())
        {
            set.erase(val); // Remove from set
            // Remove from vector
            data.erase(std::remove(data.begin(), data.end(), val), data.end());
            return true;
        }
        return false;
    }

    // Returns a random element from the set.
    int getRandom()
    {
        int randomIndex = rand() % data.size(); // Pick a random index
        return data[randomIndex];
    }
};