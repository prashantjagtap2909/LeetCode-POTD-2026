class Fancy {
public:
    const long long MOD = 1e9 + 7;
    vector<long long> nums;
    long long mul = 1;
    long long add = 0;

    long long modPow(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    long long modInv(long long x) {
        return modPow(x, MOD - 2);
    }

    Fancy() {}

    void append(int val) {
        long long v = (val - add) % MOD;
        if (v < 0) v += MOD;
        v = v * modInv(mul) % MOD;
        nums.push_back(v);
    }

    void addAll(int inc) {
        add = (add + inc) % MOD;
    }

    void multAll(int m) {
        mul = mul * m % MOD;
        add = add * m % MOD;
    }

    int getIndex(int idx) {
        if (idx >= nums.size()) return -1;
        return (nums[idx] * mul + add) % MOD;
    }
};
