# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

class Solution {
private:
    int min2(int a, int b, int c) {
    return min(a,min(b, c));
}
public:
    int countSquares(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        vector<vector<int>>DP=matrix;
        // start from rows-2,cols-2 and fill rowise from bottom to top
        for(int i=rows-2;i>=0;i--){
            for(int j=cols-2;j>=0;j--){
                if(DP[i][j]!=0){
                    DP[i][j]=1+min2(DP[i+1][j],DP[i][j+1],DP[i+1][j+1]);
                }
            }
        }
        // final answer will be the sum of all element
        int total=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                total+=DP[i][j];
            }
        } 
        return total;       
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {0, 1, 1, 1},
        {1, 1, 1, 1},
        {0, 1, 1, 1}
    };
    int result = sol.countSquares(matrix);
    cout << "Total number of square submatrices with all ones: " << result << endl;
    return 0;
}