#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    vector<int> assignElements(vector<int> &groups, vector<int> &elements)
    {
        int m = elements.size();
        int n = groups.size();
        vector<int> res(n, -1);
        unordered_map<int, int> bestIndex;
        for (int i = 0; i < m; i++)
        {
            int x = elements[i];
            if (!bestIndex.count(x) || i < bestIndex[x])
                bestIndex[x] = i;
        }
        int maxGroup = 0;
        for (int g : groups)
        {
            maxGroup = max(maxGroup, g);
        }
        vector<int> minIdx(maxGroup + 1, m);
        for (auto &p : bestIndex)
        {
            int x = p.first;
            int idx = p.second;
            for (int j = x; j <= maxGroup; j += x)
            {
                minIdx[j] = min(minIdx[j], idx);
            }
        }
        for (int i = 0; i < n; i++)
        {
            int g = groups[i];
            if (minIdx[g] < m)
                res[i] = minIdx[g];
        }
        return res;
    }
};
