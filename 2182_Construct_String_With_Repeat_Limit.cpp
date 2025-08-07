# include <iostream>
# include <string>
# include <vector>
# include <unordered_map>
# include <queue>

using namespace std;

class Solution
{
public:
    string repeatLimitedString(string s, int repeatLimit)
    {
        // Create a map to store the frequency of each character in the string.
        unordered_map<char, int> freq;
        for (char c : s)
        {
            freq[c]++;
        }

        // Create a max heap to store characters by their frequency and lexicographical order.
        priority_queue<pair<char, int>> maxHeap;
        for (auto &entry : freq)
        {
            maxHeap.push({entry.first, entry.second});
        }

        string result;
        while (!maxHeap.empty())
        {
            auto [char1, count1] = maxHeap.top();
            maxHeap.pop();

            // Add the character to the result string up to repeatLimit times.
            int times = min(count1, repeatLimit);
            result.append(times, char1);
            count1 -= times;

            if (count1 > 0)
            {
            if (maxHeap.empty())
            {
                break;
            }

            auto [char2, count2] = maxHeap.top();
            maxHeap.pop();

            // Add one instance of the next largest character to break the sequence.
            result.push_back(char2);
            count2--;

            if (count2 > 0)
            {
                maxHeap.push({char2, count2});
            }

            // Push the first character back into the heap with the remaining count.
            maxHeap.push({char1, count1});
            }
        }

        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution obj;
    string s = "abc";
    int repeatLimit = 3;
    cout << obj.repeatLimitedString(s, repeatLimit) << endl;
    return 0;
}