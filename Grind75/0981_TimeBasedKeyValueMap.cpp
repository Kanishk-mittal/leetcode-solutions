#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class TimeMap
{
private:
    unordered_map<string, vector<pair<int, string>>> mp;

    string binSearch(int timestamp, vector<pair<int, string>> &values)
    {
        int l = 0;
        int r = values.size() - 1;
        string result = "";

        while (l <= r)
        {
            int mid = l + (r - l) / 2;

            if (values[mid].first <= timestamp)
            {
                result = values[mid].second;
                l = mid + 1; // try to find larger valid timestamp
            }
            else
            {
                r = mid - 1;
            }
        }
        return result;
    }

public:
    void set(string key, string value, int timestamp)
    {
        mp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp)
    {
        if (mp.find(key) == mp.end())
            return "";
        return binSearch(timestamp, mp[key]);
    }
};
/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

int main()
{
    TimeMap sol;
    return 0;
}