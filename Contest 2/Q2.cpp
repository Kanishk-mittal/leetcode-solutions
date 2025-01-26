# include <iostream>
# include <vector>
# include <string>
# include <algorithm>       

using namespace std;

class Solution
{
private:
    vector<int> get_users(string mention_string){
        vector<int> mentions;
        // split mention_string by ' ' and store it in mentions
        string temp = "";
        for (int i = 0; i < mention_string.size(); i++)
        {
            if (mention_string[i] == ' ')
            {
                mentions.push_back(stoi(temp.substr(2)));
                temp = "";
            }
            else
            {
                temp += mention_string[i];
            }
        }
        mentions.push_back(stoi(temp.substr(2)));
        return mentions;
    }
public :
vector<int> countMentions(int numberOfUsers, vector<vector<string>> &events)
    {
        /*
        Steps:- 
        1. Sort events by time which is given by event[i][1]
        2. Create an array of size numberOfUsers and initialize it with 0 this will hold the count of mentions of each user
        3. Create an array of size numberOfUsers and initialize it with 0 this will hold the time till which each user is offline inital value is -1
        */
        sort(events.begin(), events.end(), [](vector<string> &a, vector<string> &b) {
            if (stoi(a[1]) == stoi(b[1]))
            {
                return a[0] > b[0];
            }
            
            return stoi(a[1]) < stoi(b[1]);
        });
        vector<int> mentions(numberOfUsers, 0);
        vector<int> offline(numberOfUsers, -1);
        for (int i = 0; i < events.size(); i++)
        {
            if (events[i][0] == "MESSAGE")
            {
                if (events[i][2]=="ALL")
                {
                    for (int j = 0; j < numberOfUsers; j++)
                    {
                        mentions[j]++;
                    }
                }
                else if (events[i][2]=="HERE")
                {
                    for (int j = 0; j < numberOfUsers; j++)
                    {
                        if (offline[j]<=stoi(events[i][1]))
                        {
                            mentions[j]++;
                        }
                    }
                }
                else
                {
                    vector<int> users = get_users(events[i][2]);
                    for (int j = 0; j < users.size(); j++)
                    {
                        
                        mentions[users[j]]++;
                    }
                }
            }
            else
            {
                int user = stoi(events[i][2]);
                int timestamp = stoi(events[i][1]);
                offline[user] = timestamp+60;
            }
        }
        return mentions;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    int numberOfUsers = 3;
    vector<vector<string>> events = {{"MESSAGE", "1", "id0 id1"}, {"MESSAGE", "5", "id2"}, {"MESSAGE", "6", "ALL"}, {"OFFLINE", "5", "2"}};
    vector<int> result = s.countMentions(numberOfUsers, events);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}