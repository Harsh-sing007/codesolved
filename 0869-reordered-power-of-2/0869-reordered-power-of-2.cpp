class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s = countDigits(n);
        for (int i = 0; i < 31; ++i) { // 2^0 to 2^30
            if (s == countDigits(1 << i)) return true;
        }
        return false;
    }

private:
    string countDigits(int num) {
        string cnt(10, '0');
        while (num > 0) {
            cnt[num % 10]++;
            num /= 10;
        }
        return cnt;
    }
};
