# include <iostream>
# include <vector>
# include <set>
# include <string>

using namespace std;

class Solution {
private:
    void build(set<string>& result, string & curr, int opening, int closing){
        if (opening==0 && closing ==0)
        {
            result.insert(curr);
        }
        if (opening)
        {
            opening--;
            curr.push_back('(');
            build(result, curr, opening, closing);
            curr.pop_back();
            opening++;
        }
        if (closing && closing>opening)
        {
            closing --;
            curr.push_back(')');
            build(result, curr, opening, closing);
            closing++;
            curr.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        set<string> result;
        string curr="";
        build(result,curr,n,n);
        return vector<string>(result.begin(), result.end());
    }
};