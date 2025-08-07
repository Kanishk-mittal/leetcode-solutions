# include <iostream>
# include <vector>

using namespace std;

class Solution
{
public:
    bool canBeValid(string s, string locked)
    {
        if (s.size()%2 != 0)
        {
            return false;
        }
        int locked_open = 0;
        int locked_close = 0;
        int unlocked = 0;
        // checking left to right
        for (int i = 0; i < s.size(); i++)
        {
            if (locked[i]=='0'){
                unlocked++;
            }
            else if (locked[i]=='1'){
                if (s[i]=='(')
                {
                    locked_open++;
                }
                else{
                    if (locked_open>0)
                    {
                        locked_open--;
                    }
                    else if (unlocked>0)
                    {
                        unlocked--;
                    }
                    else{
                        return false;
                    }                                        
                }
            }
        }
        // checking right to left
        locked_open = 0;
        locked_close = 0;
        unlocked = 0;
        for (int i = s.size()-1; i >= 0; i--)
        {
            if (locked[i]=='0'){
                unlocked++;
            }
            else if (locked[i]=='1'){
                if (s[i]==')')
                {
                    locked_close++;
                }
                else{
                    if (locked_close>0)
                    {
                        locked_close--;
                    }
                    else if (unlocked>0)
                    {
                        unlocked--;
                    }
                    else{
                        return false;
                    }                                        
                }
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution obj;
    string s = "))()))";
    string locked = "010100";
    cout << obj.canBeValid(s, locked) << endl;
    return 0;
}