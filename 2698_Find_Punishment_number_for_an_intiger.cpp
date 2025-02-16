# include <iostream>
# include <vector>

using namespace std;

class Solution
{
private:
    bool checkParittions(int n, int sum){
        // this will recursivly check if the n can be partitioned into some part such that sum of all parts is equal to sum
        if (n==sum){
            return true;
        }
        if (n<sum){
            return false;
        }
        if (sum<=0){
            return false;
        }
        int i = 10;
        while(n/i !=0){
            if (checkParittions(n/i, sum - (n%i))){
                return true;
            }
            i*=10;
        }
        return false;
    }
public:
    int punishmentNumber(int n)
    {
        int punishment =0;
        for (int i = 1; i <= n; i++)
        {
            if (checkParittions(i*i, i)){
                punishment += i * i;
            }
        }
        return punishment;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}