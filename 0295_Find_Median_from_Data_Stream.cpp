#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class MedianFinder
{
private:
    priority_queue<int> left;                             // Max heap for lower half
    priority_queue<int, vector<int>, greater<int>> right; // Min heap for upper half

public:
    MedianFinder() {}

    void addNum(int num)
    {
        // 1. Push to left max-heap first
        left.push(num);

        // 2. Balancing: Ensure every element in left <= every element in right
        // We do this by moving left's largest to right
        right.push(left.top());
        left.pop();

        // 3. Maintain size property: left can have at most 1 more element than right
        if (left.size() < right.size())
        {
            left.push(right.top());
            right.pop();
        }
    }

    double findMedian()
    {
        if (left.size() > right.size())
        {
            return (double)left.top();
        }
        else
        {
            // Use 2.0 to ensure floating point division
            return (left.top() + right.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main()
{
    MedianFinder sol;
    sol.addNum(-1);
    cout << sol.findMedian() << endl;
    sol.addNum(-2);
    cout << sol.findMedian() << endl;
    sol.addNum(-3);
    cout << sol.findMedian() << endl;
    sol.addNum(-4);
    cout << sol.findMedian() << endl;
    sol.addNum(-5);
    cout << sol.findMedian() << endl;
    return 0;
}