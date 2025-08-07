# include <iostream>
# include <vector>

using namespace std;

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        /*
        Algorithm:
        1. Initialize a vector `candies` of the same size as `ratings`, filled with 1s.
        2. Traverse the `ratings` from left to right:
            - If the current rating is greater than the previous one, increment the current candy count based on the previous candy count.
        3. Traverse the `ratings` from right to left:
            - If the current rating is greater than the next one, ensure the current candy count is greater than the next candy count.
        4. Sum up all the values in the `candies` vector to get the total number of candies.
        5. Return the total count of candies.
        */
        int n = ratings.size();
        if (n == 0) return 0;
        vector<int> candies(n, 1);
        // Left to right pass
        for (int i = 1; i < n; ++i)
        {
            if (ratings[i] > ratings[i - 1])
            {
                candies[i] = candies[i - 1] + 1;
            }
        }
        // Right to left pass
        for (int i = n - 2; i >= 0; --i)
        {
            if (ratings[i] > ratings[i + 1])
            {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }
        // Calculate the total candies
        int totalCandies = 0;
        for (int candy : candies)
        {
            totalCandies += candy;
        }
        return totalCandies;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}