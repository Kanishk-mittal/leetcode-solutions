# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

class Solution
{
private:
    void getHappyStrings(int n,vector<char> chars, string current, vector<string> &happyStrings)
    {
        if(current.size()==n)
        {
            happyStrings.push_back(current);
            return;
        }
        for(char c:chars)
        {
            if(current.empty() || current.back()!=c)
            {
                vector<char> temp={'a', 'b', 'c'};
                temp.erase(find(temp.begin(), temp.end(), c));
                getHappyStrings(n, temp, current+c, happyStrings);
            }
        }
    }
public:
    string getHappyString(int n, int k)
    {
        vector<string> happyStrings;
        getHappyStrings(n, {'a', 'b', 'c'}, "", happyStrings);
        return k<=happyStrings.size()?happyStrings[k-1]:"";
    }
};

int main(int argc, char const *argv[])
{
    int n = 3, k = 9;
    Solution obj;
    cout<<obj.getHappyString(n, k)<<endl;
    return 0;
}