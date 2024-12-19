# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

class Solution
{
public:
    int maxChunksToSorted(vector<int> &arr)
    {
        if (arr.size() == 0)
        {
            return 0;
        }
        
        int count = 0;
        int max_num = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            max_num = max(max_num, arr[i]);
            if (max_num == i)
            {
                count++;
            }
        }
        return count;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> arr = {4, 3, 2, 1, 0};
    cout << sol.maxChunksToSorted(arr) << endl;
    vector<int> arr1 = {1, 0, 2, 3, 4};
    cout << sol.maxChunksToSorted(arr1) << endl;
    return 0;
}