# include <iostream>
# include <vector>
# include <unordered_map>

using namespace std;

class Solution
{
public:
    int maxDistance(string s, int k)
    {
        unordered_map<char, int> changes = {
            {'N', 1},
            {'S', -1},
            {'E', 1},
            {'W', -1}};
        int n = s.size();
        vector<int> transformed(n);
        for (int i = 0; i < n; i++)
        {
            transformed[i] = changes[s[i]];
        }
        int max_sum = 0;
        int sum = 0;
        for (int i = 0; i < k; i++)
        {
            sum += transformed[i];
            max_sum = max(max_sum, abs(sum));
        }
        if (k==0)
        {
            return max_sum;
        }
        
        for (int i = 0; i < n; i++)
        {
            if (k == 0)
            {
                break;
            }
            
            if (max_sum<0)
            {
                if (transformed[i] == 1)
                {
                    transformed[i] = -1;
                    k--;
                }                
            }
            if (max_sum>0)
            {
                if (transformed[i] == -1)
                {
                    transformed[i] = 1;
                    k--;
                }
            }            
        }
        max_sum = 0;
        sum = 0;
        for (int i = 0; i < k; i++)
        {
            sum += transformed[i];
            max_sum = max(max_sum, abs(sum));
        }
        return max_sum;
    }
};

    int
    main(int argc, char const *argv[])
{
    string s = "WEES";
    int k = 2;
    Solution sol;
    cout << sol.maxDistance(s, k) << endl; // Output: 3
    return 0;
}