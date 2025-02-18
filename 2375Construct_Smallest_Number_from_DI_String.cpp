# include <iostream>
# include <vector>

using namespace std;

class Solution
{
public:
    string smallestNumber(string pattern)
    {
        // Only digits '1' to '9' are allowed.
        vector<char> available = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        string ans;
        bool found = false;
        backtrack(pattern, 0, "", available, ans, found);
        return ans;
    }

private:
    // index: how many digits have been placed so far.
    // current: current number being built.
    // available: digits still available.
    // ans: the answer (set once a complete valid number is found).
    // found: flag to indicate we found the valid answer.
    void backtrack(const string &pattern, int index, string current,
                   vector<char> available, string &ans, bool &found)
    {
        // When we've placed n+1 digits (pattern length n)
        if (index == pattern.size() + 1)
        {
            ans = current;
            found = true;
            return;
        }

        // Try available digits in ascending order.
        for (int i = 0; i < available.size(); i++)
        {
            char candidate = available[i];

            // If this is not the first digit, check the relationship.
            if (index > 0)
            {
                char last = current.back();
                // The pattern character to check is at position index-1.
                if (pattern[index - 1] == 'I' && last >= candidate)
                    continue;
                if (pattern[index - 1] == 'D' && last <= candidate)
                    continue;
            }

            // Choose candidate digit and remove it from available.
            vector<char> nextAvailable = available;
            nextAvailable.erase(nextAvailable.begin() + i);

            backtrack(pattern, index + 1, current + candidate, nextAvailable, ans, found);
            if (found)
                return; // Stop as soon as we find a valid answer.
        }
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}