#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    long long findScore(vector<int> &nums)
    {
        long long score = 0;
        int n = nums.size();
        vector<bool> marked(n, false);

        // Min-heap to store elements along with their indices
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;

        // Initialize the min-heap with all elements and their indices
        for (int i = 0; i < n; ++i)
        {
            minHeap.emplace(nums[i], i);
        }

        while (!minHeap.empty())
        {
            auto [value, index] = minHeap.top();
            minHeap.pop();

            // Skip if the element is already marked
            if (marked[index])
                continue;

            // Add the value to the score
            score += value;

            // Mark the current element and its neighbors
            marked[index] = true;
            if (index > 0)
                marked[index - 1] = true;
            if (index < n - 1)
                marked[index + 1] = true;
        }

        return score;
    }
};

// Example usage
int main()
{
    Solution sol;
    vector<int> nums = {4, 2, 7, 1, 8, 3};
    cout << "Score: " << sol.findScore(nums) << endl;
    return 0;
}
