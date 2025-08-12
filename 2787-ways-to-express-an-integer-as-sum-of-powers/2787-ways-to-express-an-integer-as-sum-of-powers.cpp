#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mod = 1e9 + 7;
    unordered_map<string, int> memo;

    int numberOfWays(int n, int x) {
        return dfs(n, 1, x);
    }

    int dfs(int remaining, int start, int power) {
        if (remaining == 0) return 1;
        if (remaining < 0) return 0;

        string key = to_string(remaining) + "," + to_string(start);
        if (memo.count(key)) return memo[key];

        long long ans = 0;
        for (int i = start; pow(i, power) <= remaining; i++) {
            ans += dfs(remaining - (int)pow(i, power), i + 1, power);
            ans %= mod;
        }

        return memo[key] = ans;
    }
};

