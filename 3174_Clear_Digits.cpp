# include <iostream>
# include <vector>
using namespace std;

class Solution
{
public:
    string clearDigits(string s)
    {
        vector<bool> toRemove(s.size());
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                toRemove[i] = true;
                int temp = i;
                while (toRemove[temp] == true)
                {
                    temp--;
                }  
                toRemove[temp] = true;              
            }
        }
        string result = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (!toRemove[i])
            {
                result += s[i];
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}