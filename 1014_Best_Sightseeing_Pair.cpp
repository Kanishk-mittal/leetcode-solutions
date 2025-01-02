# include <iostream>
# include <vector>

using namespace std;

class Solution
{
public:
    int maxScoreSightseeingPair(vector<int> &values)
    {
        int n = values.size();
        int maxScore = 0;
        int maxI = values[0];
        for (int j = 1; j < n; j++)
        {
            maxScore = max(maxScore, maxI + values[j] - j);
            maxI = max(maxI, values[j] + j);
        }
        return maxScore;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}