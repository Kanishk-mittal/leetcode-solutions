# include <iostream>
# include <vector>
# include <sstream>
using namespace std;

class Solution
{
public:
    string simplifyPath(string path)
    {
        vector<string> folders;
        string folder;
        stringstream ss(path);

        while (getline(ss, folder, '/'))
        {
            if (folder == "" || folder == ".")
                continue;
            if (folder == "..")
            {
                if (!folders.empty())
                    folders.pop_back();
            }
            else
            {
                folders.push_back(folder);
            }
        }

        string result;
        for (const string &f : folders)
        {
            result += "/" + f;
        }

        return result.empty() ? "/" : result;
    }
};