class Solution {
public:
    double soupServings(int n) {
        if (n >= 4800) return 1.0; 

        unordered_map<int, unordered_map<int, double>> memo;
        return dfs((n + 24) / 25, (n + 24) / 25, memo);
    }

    double dfs(int a, int b, unordered_map<int, unordered_map<int, double>>& memo) {
        if (a <= 0 && b <= 0) return 0.5;
        if (a <= 0) return 1.0;
        if (b <= 0) return 0.0;
        if (memo[a][b]) return memo[a][b];

        double res = 0.25 * (
            dfs(a - 4, b, memo) +
            dfs(a - 3, b - 1, memo) +
            dfs(a - 2, b - 2, memo) +
            dfs(a - 1, b - 3, memo)
        );

        memo[a][b] = res;
        return res;
    }
};
