class Solution {
public:
    int minOperations(string s, int k) {

        int n = s.size();
        int z = 0;

        for(char c : s)
            if(c == '0')
                z++;

        // Already all ones
        if(z == 0)
            return 0;

        // If k = n
        if(k == n){
            if(z == n) return 1;
            return -1;
        }

        // Try operations safely
        for(long long t = 1; t <= 2LL*n; t++){

            long long flips = t * k;

            if(flips < z)
                continue;

            if((flips - z) % 2 != 0)
                continue;

            // Must be distributable
            if(flips > t * n)
                continue;

            return (int)t;
        }

        return -1;
    }
};