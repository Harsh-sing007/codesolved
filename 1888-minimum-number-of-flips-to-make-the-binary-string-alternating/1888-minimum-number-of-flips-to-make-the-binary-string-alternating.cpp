class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        string ss = s + s;
        int diff1 = 0, diff2 = 0;
        int ans = INT_MAX;
        for (int i = 0; i < ss.size(); i++) {
            char alt1 = (i % 2 == 0) ? '0' : '1';
            char alt2 = (i % 2 == 0) ? '1' : '0';
            if (ss[i] != alt1) diff1++;
            if (ss[i] != alt2) diff2++;
            if (i >= n) {
                int j = i - n;
                char prev1 = (j % 2 == 0) ? '0' : '1';
                char prev2 = (j % 2 == 0) ? '1' : '0';
                if (ss[j] != prev1) diff1--;
                if (ss[j] != prev2) diff2--;
            }
            if (i >= n - 1) {
                ans = min(ans, min(diff1, diff2));
            }
        }
        return ans;
    }
};