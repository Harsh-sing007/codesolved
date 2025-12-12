class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        vector<int> lps(n, 0);
        
        // Build LPS array
        for (int i = 1, len = 0; i < n; ) {
            if (s[i] == s[len]) {
                lps[i++] = ++len;
            } 
            else if (len > 0) {
                len = lps[len - 1];
            } 
            else {
                lps[i++] = 0;
            }
        }
        
        int last = lps[n - 1];
        
        // Check repeat condition
        return (last > 0 && n % (n - last) == 0);
    }
};
