# include <iostream>
# include <vector>  

using namespace std;

class Solution
{
public:
    bool doesValidArrayExist(vector<int> &derived)
    {
        int output = 0;
        for (int i = 0; i < derived.size(); i++)
        {
            output^=derived[i];
        }
        return output==0?true:false;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}