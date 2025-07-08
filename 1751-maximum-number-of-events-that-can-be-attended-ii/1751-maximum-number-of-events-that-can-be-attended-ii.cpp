#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        // Sort events by end time
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int n = events.size();
        vector<int> endTimes(n);
        for (int i = 0; i < n; ++i)
            endTimes[i] = events[i][1];

        // dp[i][j] = max value we can get using first i events and attending j events
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        for (int i = 1; i <= n; ++i) {
            int start = events[i - 1][0], value = events[i - 1][2];

            // Find the last event that ends before the current event starts
            int prev = upper_bound(endTimes.begin(), endTimes.end(), start - 1) - endTimes.begin();
            
            for (int j = 1; j <= k; ++j) {
                // Option 1: skip this event
                // Option 2: take this event and add its value
                dp[i][j] = max(dp[i - 1][j], dp[prev][j - 1] + value);
            }
        }

        return dp[n][k];
    }
};
