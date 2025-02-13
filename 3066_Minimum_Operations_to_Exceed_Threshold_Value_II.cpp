#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        priority_queue<long long, vector<long long>, greater<long long>> pq(nums.begin(), nums.end());
        int count = 0;
        while (pq.size() > 1 && pq.top() < k)
        {
            long long min1 = pq.top();
            pq.pop();
            long long min2 = pq.top();
            pq.pop();
            long long new_cookie = 2 * min1 + min2;
            pq.push(new_cookie);
            count++;
        }
        return count;
    }
};
int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 9, 10, 12};
    int k = 7;
    cout << sol.minOperations(nums, k) << endl;
    return 0;
}
