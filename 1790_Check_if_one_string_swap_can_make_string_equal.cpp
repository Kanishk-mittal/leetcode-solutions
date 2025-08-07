# include <iostream>

using namespace std;
class Solution
{
public:
    bool areAlmostEqual(string s1, string s2)
    {
        int n = s1.size();
        int MismatchCount = 0;
        int MismatchIndex1 = -1;
        int MismatchIndex2 = -1;
        for (int i = 0; i < n; i++)
        {
            if (s1[i] != s2[i])
            {
                MismatchCount++;
                if (MismatchCount == 1)
                {
                    MismatchIndex1 = i;
                }
                else if (MismatchCount == 2)
                {
                    MismatchIndex2 = i;
                }
                else
                {
                    return false;
                }
            }
        }
        if (MismatchCount == 0)
        {
            return true;
        }
        if (MismatchCount == 2)
        {
            if (s1[MismatchIndex1] == s2[MismatchIndex2] && s1[MismatchIndex2] == s2[MismatchIndex1])
            {
                return true;
            }
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}