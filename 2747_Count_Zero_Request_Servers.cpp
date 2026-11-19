#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int q_size = queries.size();
        
        // Pair queries with their original index: {query_time, original_index}
        vector<pair<int, int>> sorted_queries(q_size);
        for (int i = 0; i < q_size; i++) {
            sorted_queries[i] = {queries[i], i};
        }
        
        // 1. Sort queries and logs by timestamp
        sort(sorted_queries.begin(), sorted_queries.end());
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        vector<int> result(q_size);
        vector<int> server_counts(n + 1, 0);
        int active_servers = 0;
        
        int left = 0;
        int right = 0;
        int num_logs = logs.size();
        
        // 2. Process queries using sliding window
        for (const auto& [q_time, original_idx] : sorted_queries) {
            int window_start = q_time - x;
            
            // Add logs that fall within the current query's end time
            while (right < num_logs && logs[right][1] <= q_time) {
                int server = logs[right][0];
                if (server_counts[server] == 0) {
                    active_servers++;
                }
                server_counts[server]++;
                right++;
            }
            
            // Remove logs that fall strictly before the window start time
            while (left < num_logs && logs[left][1] < window_start) {
                int server = logs[left][0];
                server_counts[server]--;
                if (server_counts[server] == 0) {
                    active_servers--;
                }
                left++;
            }
            
            // Inactive (idle) servers = total servers - active servers
            result[original_idx] = n - active_servers;
        }
        
        return result;
    }
};