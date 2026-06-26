#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxBuilding(int n, vector<vector<int>> &restrictions)
    {
        // Step 1: Add default restrictions for the start and end buildings
        restrictions.push_back({1, 0});

        // Check if restriction for 'n' already exists, if not, add it
        bool hasN = false;
        for (const auto &r : restrictions)
        {
            if (r[0] == n)
            {
                hasN = true;
                break;
            }
        }
        if (!hasN)
        {
            restrictions.push_back({n, n - 1});
        }

        // Step 2: Sort restrictions by building index
        sort(restrictions.begin(), restrictions.end());

        int m = restrictions.size();

        // Step 3: Left-to-right pass
        for (int i = 1; i < m; i++)
        {
            restrictions[i][1] = min(restrictions[i][1],
                                     restrictions[i - 1][1] + (restrictions[i][0] - restrictions[i - 1][0]));
        }

        // Step 4: Right-to-left pass
        for (int i = m - 2; i >= 0; i--)
        {
            restrictions[i][1] = min(restrictions[i][1],
                                     restrictions[i + 1][1] + (restrictions[i + 1][0] - restrictions[i][0]));
        }

        // Step 5: Calculate the maximum height between restrictions
        int maxH = 0;
        for (int i = 1; i < m; i++)
        {
            int dist = restrictions[i][0] - restrictions[i - 1][0];
            int h1 = restrictions[i - 1][1];
            int h2 = restrictions[i][1];

            // Peak formula between two points
            int peak = (dist + h1 + h2) / 2;
            maxH = max(maxH, peak);
        }

        return maxH;
    }
};

int main()
{
    Solution sol;
    int n = 5;
    vector<vector<int>> restrictions = {{2, 1},
                                        {4, 1}};
    cout << sol.maxBuilding(n, restrictions) << endl;
    return 0;
}