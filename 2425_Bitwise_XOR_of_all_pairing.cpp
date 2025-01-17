# include <iostream>
# include <vector>

using namespace std;

class Solution
{
public:
    int xorAllNums(vector<int> &nums1, vector<int> &nums2)
    {
        int xorSum = 0;
        if (nums2.size()%2!=0)
        {
            for (int i = 0; i < nums1.size(); i++)
            {
                xorSum ^= nums1[i];
            }
            
        }
        if (nums1.size()%2!=0)
        {
            for (int i = 0; i < nums2.size(); i++)
            {
                xorSum ^= nums2[i];
            }
        }
        return xorSum;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}