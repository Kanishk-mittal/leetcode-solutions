# include <iostream>
# include <vector>

using namespace std;

class Solution
{
private:
    string longestCommonSubsequence(string str1, string str2){
        int m = str1.size();
        int n = str2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        string lcs = "";
        int i = m, j = n;
        while(i > 0 && j > 0){
            if(str1[i-1] == str2[j-1]){
                lcs = str1[i-1] + lcs;
                i--;
                j--;
            }else{
                if(dp[i-1][j] > dp[i][j-1]){
                    i--;
                }else{
                    j--;
                }
            }
        }
        return lcs;
    }
public:
    string shortestCommonSupersequence(string str1, string str2)
    {
        string lcs = longestCommonSubsequence(str1, str2);
        string superSeq = "";
        // adding remaining characters from str1 and str2
        int i = 0, j = 0;
        for(char ch : lcs){
            while(str1[i] != ch){
                superSeq += str1[i++];
            }
            while(str2[j] != ch){
                superSeq += str2[j++];
            }
            superSeq += ch;
            i++;
            j++;
        }
        superSeq += str1.substr(i) + str2.substr(j);
        return superSeq;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}