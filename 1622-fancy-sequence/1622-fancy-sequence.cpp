class Fancy {
public:
    const long long MOD = 1000000007;
    
    vector<long long> seq;
    long long mul = 1;
    long long add = 0;

    Fancy() {}

    long long modPow(long long a, long long b) {
        long long res = 1;
        a %= MOD;
        while (b) {
            if (b & 1) res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }

    long long modInverse(long long x) {
        return modPow(x, MOD - 2);
    }

    void append(int val) {
        long long x = (val - add + MOD) % MOD;
        x = (x * modInverse(mul)) % MOD;
        seq.push_back(x);
    }

    void addAll(int inc) {
        add = (add + inc) % MOD;
    }

    void multAll(int m) {
        mul = (mul * m) % MOD;
        add = (add * m) % MOD;
    }

    int getIndex(int idx) {
        if (idx >= seq.size()) return -1;
        long long val = seq[idx];
        return (val * mul + add) % MOD;
    }
};