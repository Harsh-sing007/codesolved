class Solution {
public:
    int concatenatedBinary(int n) {
        
        const int MOD = 1000000007;
        long long result = 0;
        int bits = 0;

        for(int i = 1; i <= n; i++) {
            
            // Increase bit count when i is power of 2
            if((i & (i - 1)) == 0)
                bits++;

            result = ((result << bits) + i) % MOD;
        }

        return result;
    }
};