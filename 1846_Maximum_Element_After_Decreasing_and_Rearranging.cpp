#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int> &arr)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        arr[0] = 1;
        for (int i = 1; i < n; i++)
        {
            arr[i] = min(arr[i - 1] + 1, arr[i]);
        }
        return arr[n - 1];
    }
};

int main()
{
    Solution sol;
    // case 1
    vector<int> arr_1 = {2, 2, 1, 2, 1};
    cout << sol.maximumElementAfterDecrementingAndRearranging(arr_1) << endl;

    // case 2
    vector<int> arr_2 = {100, 1, 1000};
    cout << sol.maximumElementAfterDecrementingAndRearranging(arr_2) << endl;

    // case 3
    vector<int> arr_3 = {1, 2, 3, 4, 5};
    cout << sol.maximumElementAfterDecrementingAndRearranging(arr_3) << endl;
    return 0;
}