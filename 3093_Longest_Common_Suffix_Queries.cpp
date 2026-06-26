#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Flattened Trie Node
struct TrieNode
{
    int children[26];
    int best_idx;

    TrieNode(int idx)
    {
        best_idx = idx;
        // Initialize all child indices to -1 (meaning no child exists)
        fill(begin(children), end(children), -1);
    }
};

class Solution
{
public:
    vector<int> stringIndices(vector<string> &wordsContainer, vector<string> &wordsQuery)
    {
        int n = wordsContainer.size();

        // Find the absolute best word for a completely empty suffix
        int global_best_idx = 0;
        for (int i = 1; i < n; i++)
        {
            if (wordsContainer[i].length() < wordsContainer[global_best_idx].length())
            {
                global_best_idx = i;
            }
        }

        // Use a vector to store all nodes continuously in memory.
        vector<TrieNode> trie;
        // Pre-allocate memory based on problem constraints (sum of lengths <= 5 * 10^5)
        // This prevents the vector from reallocating and copying data under the hood.
        trie.reserve(500005);

        // Root node sits at index 0
        trie.emplace_back(global_best_idx);

        // Helper lambda to update the best_idx
        auto updateBest = [&](int node_idx, int curr_idx)
        {
            int current_best = trie[node_idx].best_idx;
            int curr_len = wordsContainer[curr_idx].length();
            int best_len = wordsContainer[current_best].length();

            if (curr_len < best_len)
            {
                trie[node_idx].best_idx = curr_idx;
            }
            else if (curr_len == best_len && curr_idx < current_best)
            {
                trie[node_idx].best_idx = curr_idx;
            }
        };

        // 1. Build the Trie with reversed words
        for (int i = 0; i < n; i++)
        {
            int curr_node = 0; // Start at root
            updateBest(curr_node, i);

            // Pass by const reference to avoid string copies
            const string &w = wordsContainer[i];

            for (int j = w.length() - 1; j >= 0; j--)
            {
                int c = w[j] - 'a';
                // If child doesn't exist, create it and link the index
                if (trie[curr_node].children[c] == -1)
                {
                    trie[curr_node].children[c] = trie.size();
                    trie.emplace_back(i);
                }
                // Move to the child node
                curr_node = trie[curr_node].children[c];
                updateBest(curr_node, i);
            }
        }

        // 2. Process Queries
        vector<int> ans(wordsQuery.size());
        for (int i = 0; i < wordsQuery.size(); i++)
        {
            int curr_node = 0;
            const string &q = wordsQuery[i];

            for (int j = q.length() - 1; j >= 0; j--)
            {
                int c = q[j] - 'a';
                if (trie[curr_node].children[c] == -1)
                {
                    break;
                }
                curr_node = trie[curr_node].children[c];
            }
            ans[i] = trie[curr_node].best_idx;
        }

        return ans;
    }
};