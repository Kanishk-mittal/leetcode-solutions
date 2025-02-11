# include <iostream>
# include <unordered_map>
# include <set>

using namespace std;

class NumberContainers
{
private:
    std::unordered_map<int, std::set<int>> container; // Maps number -> set of indices
    std::unordered_map<int, int> pairs;               // Maps index -> number

public:
    NumberContainers()
    {
        container.clear();
        pairs.clear();
    }

    void change(int index, int number)
    {
        // If index already exists, remove it from the previous number's set
        if (pairs.find(index) != pairs.end())
        {
            int oldNumber = pairs[index];
            container[oldNumber].erase(index);
            // Clean up if the set becomes empty
            if (container[oldNumber].empty())
            {
                container.erase(oldNumber);
            }
        }

        // Insert into the new number's set
        container[number].insert(index);
        // Update the mapping
        pairs[index] = number;
    }

    int find(int number)
    {
        // If number exists and has indices, return the smallest one
        if (container.find(number) != container.end() && !container[number].empty())
        {
            return *container[number].begin();
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */

int main(int argc, char const *argv[])
{
    

    return 0;
}