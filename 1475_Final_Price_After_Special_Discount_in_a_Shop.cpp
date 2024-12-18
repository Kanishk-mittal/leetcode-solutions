#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> finalPrices(vector<int> &prices)
    {
        /*
        Algorithm
        1. Create a new array to store the final prices.
        2. Iterate through the prices array.
        3. For each price, iterate through the remaining prices to find the first price that is less than or equal to the current price.
        4. If a price is found, subtract it from the current price and break the loop.
        5. If no price is found, set the final price to the current price.
        6. Return the final prices array.
        */
        vector<int> finalPrices(prices.size(), 0);
        for (int i = 0; i < prices.size(); i++)
        {
            finalPrices[i] = prices[i];
            for (int j = i + 1; j < prices.size(); j++)
            {
                if (prices[j] <= prices[i])
                {
                    finalPrices[i] -= prices[j];
                    break;
                }
            }
        }
        return finalPrices;
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}