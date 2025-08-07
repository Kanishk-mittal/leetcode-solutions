#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B)
    {
        int size= A.size();
        vector<int> prefix_common_array(size, 0);
        vector<bool> found_a(size, false);
        vector<bool> found_b(size, false);
        for (int i = 0; i < size; i++)
        {
            int num1 = A[i];
            int num2 = B[i];
            found_a[num1] = true;
            found_b[num2] = true;
            if (num1 == num2)
            {
                prefix_common_array[i] += 1;
            }
            else
            {
                if (found_b[num1])
                {
                    prefix_common_array[i] += 1;
                }
                if (found_a[num2])
                {
                    prefix_common_array[i] += 1;
                }
            }
            if (i>0)
            {
                prefix_common_array[i] += prefix_common_array[i-1];
            }
        }
        return prefix_common_array;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> A = {1, 3, 2, 4};
    vector<int> B = {3, 1, 2, 4};
    Solution obj;
    vector<int> result = obj.findThePrefixCommonArray(A, B);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}