#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double angleClock(int hour, int minutes)
    {
        // 1. Force floating-point division by using .0
        double MINUTE_DEGREE_PER_MINUTE = 360.0 / 60.0; // 6 degrees
        double HOUR_DEGREE_PER_HOUR = 360.0 / 12.0;     // 30 degrees
        double HOUR_DEGREE_PER_MINUTE = 30.0 / 60.0;    // 0.5 degrees

        // 2. Calculate positions relative to 12 o'clock
        double minute_position = minutes * MINUTE_DEGREE_PER_MINUTE;
        // Handle hour 12 resetting to 0 position (12 * 30 = 360, which is same as 0)
        double hour_position = ((hour % 12) * HOUR_DEGREE_PER_HOUR) + (minutes * HOUR_DEGREE_PER_MINUTE);

        // 3. Find the absolute difference
        double result = abs(hour_position - minute_position);

        // 4. If the angle is greater than 180, take the smaller interior angle
        if (result > 180.0)
        {
            result = 360.0 - result;
        }

        return result;
    }
};

int main()
{
    Solution sol;
    return 0;
}