class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const int MOD = 1e9 + 7;

        vector<vector<vector<long long>>> dp(
            zero + 1, vector<vector<long long>>(one + 1, vector<long long>(2, 0)));

        if (zero > 0) dp[1][0][0] = 1;
        if (one > 0) dp[0][1][1] = 1;

        for (int i = 0; i <= zero; i++) {
            for (int j = 0; j <= one; j++) {

                if (i > 0) {
                    dp[i][j][0] =
                        ((dp[i-1][j][0] + dp[i-1][j][1]) % MOD);

                    if (i - limit - 1 >= 0)
                        dp[i][j][0] =
                        (dp[i][j][0] - dp[i-limit-1][j][1] + MOD) % MOD;
                }

                if (j > 0) {
                    dp[i][j][1] =
                        ((dp[i][j-1][0] + dp[i][j-1][1]) % MOD);

                    if (j - limit - 1 >= 0)
                        dp[i][j][1] =
                        (dp[i][j][1] - dp[i][j-limit-1][0] + MOD) % MOD;
                }
            }
        }

        return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
    }
};