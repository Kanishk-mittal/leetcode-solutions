#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class UF
{
private:
    vector<int> parent;

public:
    UF(int n)
    {
        parent.reserve(n);
        for (int i = 0; i < n; i++)
        {
            parent.push_back(i);
        }
    }

    int find(int i)
    {
        if (parent[i] == i)
        {
            return i;
        }
        // FIXED: Added the return statement for path compression
        return parent[i] = find(parent[i]);
    }

    void merge(int a, int b)
    {
        int pa = find(a);
        int pb = find(b);
        if (pa != pb)
        {
            parent[pa] = pb;
        }
    }
};

class Solution
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        int n = accounts.size();
        UF u(n);

        // Map to store <email, account_index>
        unordered_map<string, int> emailToIndex;

        // Step 1: Map emails to indices and union accounts with common emails
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < accounts[i].size(); j++)
            {
                string email = accounts[i][j];

                if (emailToIndex.find(email) == emailToIndex.end())
                {
                    // First time seeing this email, map it to the current account index
                    emailToIndex[email] = i;
                }
                else
                {
                    // We've seen this email before! Merge the current account with the previous one
                    u.merge(i, emailToIndex[email]);
                }
            }
        }

        // Step 2: Group emails by their root parent (as you requested)
        unordered_map<int, vector<string>> rootToEmails;

        for (auto &pair : emailToIndex)
        {
            string email = pair.first;
            int accIndex = pair.second;

            // Find the ultimate root parent for this account
            int root = u.find(accIndex);
            rootToEmails[root].push_back(email);
        }

        // Step 3: Format the final merged accounts
        vector<vector<string>> mergedAccounts;

        for (auto &pair : rootToEmails)
        {
            int rootIndex = pair.first;
            vector<string> &emails = pair.second;

            // The problem requires the emails to be sorted alphabetically
            sort(emails.begin(), emails.end());

            // Create the final account array: [Name, email1, email2...]
            vector<string> account;
            account.push_back(accounts[rootIndex][0]);                   // Get the name
            account.insert(account.end(), emails.begin(), emails.end()); // Add sorted emails

            mergedAccounts.push_back(account);
        }

        return mergedAccounts;
    }
};

int main()
{
    Solution sol;
    return 0;
}