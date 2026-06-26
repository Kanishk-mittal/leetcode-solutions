#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class MyQueue
{
private:
    stack<int> s1;
    stack<int> s2;

public:
    MyQueue()
    {
        s1 = stack<int>();
        s2 = stack<int>();
    }

    void push(int x) { s1.push(x); }

    int pop()
    {
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int result = s2.top();
        s2.pop();
        return result;
    }

    int peek()
    {
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int result = s2.top();
        return result;
    }

    bool empty() { return s1.empty() && s2.empty(); }
};

int main()
{
    return 0;
}