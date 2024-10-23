# include <iostream>
# include <vector>
# include <queue>

using namespace std;

class Solution
{
private:
    bool isMutation(string &gene1, string &gene2)
    {
        int count = 0;
        for (int i = 0; i < gene1.size(); i++)
        {
            if (gene1[i] != gene2[i])
            {
                count++;
            }
        }
        return count == 1;
    }
public:
    int minMutation(string startGene, string endGene, vector<string> &bank)
    {
        // checking itf endGene is in bank
        bool isPresent = false;
        for (string gene : bank)
        {
            if (gene == endGene)
            {
                isPresent = true;
                break;
            }
        }
        if (!isPresent){
            return -1;
        }
        // usign BFS
        queue<pair<string, int>> q;
        q.push({startGene, 0});
        while (!q.empty())
        {
            string currGene = q.front().first;
            int steps = q.front().second;
            q.pop();
            if (currGene == endGene)
            {
                return steps;
            }
            for (auto it = bank.begin(); it != bank.end();)
            {
                if (isMutation(currGene, *it))
                {
                    q.push({*it, steps + 1});
                    it = bank.erase(it); // Erase the gene from the bank to mark it as visited
                }
                else
                {
                    ++it;
                }
            }
        }
        return -1;
    }
};