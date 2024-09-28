# include <iostream>
# include <vector>
using namespace std;
class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int n = gas.size();
        int total_gas = 0;     // Total gas available.
        int current_gas = 0;   // Gas at the current station.
        int start_station = 0; // Potential starting station.

        for (int i = 0; i < n; i++)
        {
            total_gas += gas[i] - cost[i]; // Calculate the total gas available after visiting the station.

            current_gas += gas[i] - cost[i]; // Calculate the gas at the current station.

            // If we run out of gas at the current station, reset and update the potential starting station.
            if (current_gas < 0)
            {
                current_gas = 0;
                start_station = i + 1;
            }
        }

        // If the total gas available is non-negative, it means there's a solution.
        // In this case, return the starting station; otherwise, return -1.
        return (total_gas >= 0) ? start_station : -1;
    }
};