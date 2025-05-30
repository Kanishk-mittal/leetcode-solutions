# include <iostream>
# include <vector>
# include <climits>

using namespace std;

class Solution
{
private:
    vector<int> getDistances(const vector<int> &edges, int start)
    {
        vector<int> distances(edges.size(), -1);
        int distance = 0;
        int current = start;
        vector<bool> visited(edges.size(), false);
        while (current != -1 && !visited[current])
        {
            visited[current] = true;
            distances[current] = distance++;
            current = edges[current];
        }
        return distances;
    }
public:
    int closestMeetingNode(vector<int> &edges, int node1, int node2)
    {
        vector<int> distances1 = getDistances(edges, node1);
        vector<int> distances2 = getDistances(edges, node2);
        int closestNode = -1;
        int minDistance = INT_MAX;
        for (int i = 0; i < edges.size(); ++i)
        {
            if (distances1[i] != -1 && distances2[i] != -1)
            {
                int maxDistance = max(distances1[i], distances2[i]);
                if (maxDistance < minDistance)
                {
                    minDistance = maxDistance;
                    closestNode = i;
                }
                else if (maxDistance == minDistance && i < closestNode)
                {
                    closestNode = i;
                }
            }
        }
        return closestNode;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}