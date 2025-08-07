# include <iostream>
# include <vector>
# include <string>

using namespace std;

class Solution
{
public:
    vector<int> minOperations(string boxes)
    {
        /*
        Soulution :-
        1. Create a vector of int type to store the result.
        2. Create a vector of int type to store the index of 1's in the boxes.
        3. Traverse the boxes and store the index of 1's in the vector.
        4. Traverse the boxes and calculate the result.
        5. Return the result.
        */
        vector<int> result;
        vector<int> index;
        for (int i = 0; i < boxes.size(); i++)
        {
            if (boxes[i] == '1')
            {
                index.push_back(i);
            }
        }
        for (int i = 0; i < boxes.size(); i++)
        {
            int sum = 0;
            for (int j = 0; j < index.size(); j++)
            {
                sum += abs(index[j] - i);
            }
            result.push_back(sum);
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}