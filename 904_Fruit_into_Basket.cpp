# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int max_window_size = 0;
        int type1 = -1;
        int type2 = -1;
        int l = 0;
        int current_window_size = 0;
        vector<int> freq = {0, 0}; // here first index give freq of type1 and second index fice freq of type 2
        for (int r = 0; r < fruits.size(); r++)
        {
            if (fruits[r] == type1 || fruits[r] == type2)
            {
                if (fruits[r] == type1)
                {
                    freq[0]++;
                }
                else
                {
                    freq[1]++;
                }
                current_window_size++;
                max_window_size = max(max_window_size, current_window_size);
            }
            else if (type1 == -1 || type2 == -1)
            {
                if (type1 == -1)
                {
                    type1 = fruits[r];
                    freq[0]++;
                    current_window_size++;
                    max_window_size = max(max_window_size, current_window_size);
                }
                else
                {
                    type2 = fruits[r];
                    freq[1]++;
                    current_window_size++;
                    max_window_size = max(max_window_size, current_window_size);
                }
            }
            else
            {
                while (l < r)
                {
                    if (freq[0] == 0)
                    {
                        type1 = -1;
                        r--;
                        break;
                    }
                    else if (freq[1] == 0)
                    {
                        type2 = -1;
                        r--;
                        break;
                    }
                    else
                    {
                        if (fruits[l] == type1)
                        {
                            freq[0]--;
                        }
                        else if (fruits[l] == type2)
                        {
                            freq[1]--;
                        }
                        l++;
                        current_window_size--;
                    }
                }
            }
        }
        return max_window_size;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> fruits = { 3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4 };
    Solution sol;
    int result = sol.totalFruit(fruits);
    cout << "Maximum number of fruits in the basket: " << result << endl;
    return 0;
}