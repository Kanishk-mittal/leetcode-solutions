# include <iostream>
# include <vector>
# include <cmath>

using namespace std;

class Solution
{
private:
    bool is_possible(long long time, vector<int> &ranks, int cars)
    {
        long long max_count = 0;
        for (int i = 0; i < ranks.size(); i++)
        {
            max_count += sqrt(time/ranks[i]);
            if (max_count >= cars)
            {
                return true;
            }  
        }
        return false;
    }
public:
    long long repairCars(vector<int> &ranks, int cars)
    {
        long long low = 1;
        long long max_rank=0;
        for (int i = 0; i < ranks.size(); i++)
        {
            max_rank = max(max_rank, (long long)ranks[i]);
        }
        long long high = max_rank * cars * cars;
        while (low < high)
        {
            long long mid = low + (high - low) / 2;
            if (is_possible(mid, ranks, cars))
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}