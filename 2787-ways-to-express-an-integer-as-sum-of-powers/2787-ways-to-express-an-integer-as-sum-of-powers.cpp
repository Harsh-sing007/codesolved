class Solution {
public:
    int mod = 1e9 + 7;
    int dp[301][301];

    int solve(int n, int x, int num) {
        long long power = pow(num, x);
        if (power > n) return 0;
        if (power == n) return 1;

        if (dp[n][num] != -1) return dp[n][num];

       
        int include = solve(n - power, x, num + 1);
        
        int exclude = solve(n, x, num + 1);

        return dp[n][num] = (include + exclude) % mod;
    }

    int numberOfWays(int n, int x) {
        memset(dp, -1, sizeof(dp));
        return solve(n, x, 1);
    }
};

