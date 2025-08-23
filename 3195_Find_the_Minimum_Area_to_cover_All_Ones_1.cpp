#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int min_x = grid.size(), min_y = grid[0].size();
        int max_x = -1, max_y = -1;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == 1) {
                    min_x = min(min_x, i);
                    min_y = min(min_y, j);
                    max_x = max(max_x, i);
                    max_y = max(max_y, j);
                }
            }
        }
        if(max_x < min_x) return 0;
        return (max_x - min_x + 1) * (max_y - min_y + 1);
    }
};

int main() {
    vector<vector<int>> grid = {{0,1,0},{1,0,1}};
    Solution sol;
    cout << sol.minimumArea(grid) << endl; // Output: 6
    return 0;
}