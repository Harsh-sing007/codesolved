class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        if (n < 2 || k == 0) return 0;

        vector<vector<long long>> dp(k + 1, vector<long long>(n, 0));

        for (int t = 1; t <= k; t++) {
            long long bestMinus = -prices[0]; // dp[t-1][-1] - prices[0] → treated as 0 - prices[0]
            long long bestPlus  =  prices[0]; // dp[t-1][-1] + prices[0]

            for (int i = 1; i < n; i++) {
                // Either do nothing, or finish a transaction at day i
                dp[t][i] = max({
                    dp[t][i - 1],
                    bestMinus + prices[i],   // normal buy-sell
                    bestPlus  - prices[i]    // short sell
                });

                // Update best values for future days
                bestMinus = max(bestMinus, dp[t - 1][i - 1] - prices[i]);
                bestPlus  = max(bestPlus,  dp[t - 1][i - 1] + prices[i]);
            }
        }

        return dp[k][n - 1];
    }
};
