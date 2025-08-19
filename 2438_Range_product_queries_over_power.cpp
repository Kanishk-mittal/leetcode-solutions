#include <iostream>
#include <vector>
#include <cmath>
#include <bitset>

using namespace std;

class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int MAX=1000000000+7;
        vector<int>powers;
        bitset<30> bits(n);
        for(int i=0;i<32;i++){
            if(bits[i]){
                powers.push_back(i);
            }
        }
        //calculating prefix array 
        for(int i=1;i<powers.size();i++){
            powers[i]+=powers[i-1];
        }
        //handling queris 
        vector<int>result(queries.size());
        for(int i = 0;i<queries.size();i++){
            int sum = powers[queries[i][1]]-(queries[i][0]>0?powers[queries[i][0]-1]:0);
            long long temp=1<<sum;
            result[i]=(temp%MAX);
        }
        return result;
    }
};

int main() {
    Solution solution;
    
    // Example test case
    int n = 15;
    vector<vector<int>> queries = {{0, 1}, {2, 2}, {0, 3}};
    vector<int> result = solution.productQueries(n, queries);
    
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}