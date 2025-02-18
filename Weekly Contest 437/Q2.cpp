# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

class Solution
{
public:
    long long maxWeight(vector<int> &pizzas)
    {
        sort(pizzas.begin(), pizzas.end());
        long long sum = 0;
        int n = pizzas.size();
        int pizzaEaten = n / 4;
        int oddDays = pizzaEaten / 2;
        int evenDays = pizzaEaten - oddDays;
        int j = n-1;
        for (int i = 0; i < evenDays; i++)
        {
            sum += pizzas[j];
            j--;
        }
        j --;
        for (int i = 0; i < oddDays; i++)
        {
            sum += pizzas[j];
            j -= 2;
        }        
        return sum;
    }
};

    int
    main(int argc, char const *argv[])
{
    Solution obj;
    vector<int> pizzas = {1, 2, 3, 4, 5, 6, 7, 8};
    cout << obj.maxWeight(pizzas) << endl;
    return 0;
}