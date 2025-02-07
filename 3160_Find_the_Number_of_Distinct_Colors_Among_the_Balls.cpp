# include <iostream>
# include <vector>
# include <unordered_map>
# include <unordered_set>

using namespace std;

class Solution
{
public:
    vector<int> queryResults(int limit, vector<vector<int>> &queries)
    {
        vector<int> result;
        unordered_map<int, int> colorFreq;
        unordered_map<int, int> ballColor;
        unordered_set<int> distinctColors;
        
        for (const auto &query : queries)
        {
            int ball = query[0];
            int color = query[1];
            if (ballColor.find(ball) == ballColor.end())
            {
                colorFreq[color]++;
                ballColor[ball] = color;
                if (colorFreq[color] == 1)
                {
                    distinctColors.insert(color);
                }
            }
            else
            {
                int prevColor = ballColor[ball];
                if (prevColor != color)
                {
                    colorFreq[prevColor]--;
                    if (colorFreq[prevColor] == 0)
                    {
                        distinctColors.erase(prevColor);
                    }
                    colorFreq[color]++;
                    ballColor[ball] = color;
                    if (colorFreq[color] == 1)
                    {
                        distinctColors.insert(color);
                    }
                }
            }
            result.push_back(distinctColors.size());
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}