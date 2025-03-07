# include <iostream>
# include <vector>
# include <limits>

using namespace std;

class Solution
{
private:
    bool isPrime(int n){
        if(n<2)
        {
            return false;
        }
        for (int i = 2; i*i <= n; i++)
        {
            if(n%i==0)
            {
                return false;
            }
        }
        return true;
    }
public:
    vector<int> closestPrimes(int left, int right)
    {
        vector<int> primes;
        for (int i = left; i <= right; i++)
        {
            if(isPrime(i))
            {
                primes.push_back(i);
            }
        }
        int minDiff=numeric_limits<int>::max();
        vector<int> result;
        for (int i = 0; i < primes.size()-1; i++)
        {
            if(primes[i+1]-primes[i]<minDiff)
            {
                minDiff=primes[i+1]-primes[i];
                result={primes[i],primes[i+1]};
            }
        }
        if (result.empty())
        {
            return {-1, -1};
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}