#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        // solution iterate through each diagonal save them in a temporary vector sort it and replace it 
        if(grid.size()<2){
            return grid;
        }
        int n=grid.size();
        vector<int> temp;
        // first going through bottom triangular portion including major diagonal
        for(int i=0;i<grid.size();i++){
            int j=0;
            temp.clear();
            while(i+j<n){
                temp.push_back(grid[i+j][j]);
                j++;
            }
            sort(temp.begin(),temp.end());
            j=0;
            while(i+j<n){
                grid[i+j][j]=temp[temp.size()-j-1];  // since bottom matrix need to be in descending order
                j++;
            }
        }
        //doing same for upper triangle
        for(int i=1;i<grid.size();i++){
            int j=0;
            temp.clear();
            while(i+j<n){
                temp.push_back(grid[j][i+j]);
                j++;
            }
            sort(temp.begin(),temp.end());
            j=0;
            while(i+j<n){
                grid[j][i+j]=temp[j];
                j++;
            }
        }
        return grid;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> grid = {{1, 7, 3}, {9, 8, 2}, {4, 5, 6}};
    vector<vector<int>> sortedGrid = sol.sortMatrix(grid);
    for (const auto& row : sortedGrid) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}