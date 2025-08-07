# include <iostream>

using namespace std;
class Solution
{
public:
    string removeOccurrences(string s, string part)
    {
        while (s.find(part) != string::npos)
        {
            s.erase(s.find(part), part.size());
        }
        return s;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}