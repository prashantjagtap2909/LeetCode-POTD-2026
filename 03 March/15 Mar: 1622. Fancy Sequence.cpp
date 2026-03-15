//translated using AI
class Fancy {
public:
    vector<long long> arr;
    long long MOD = 1000000007LL;

    Fancy() {
        
    }
    
    void append(int val) {
        arr.push_back(val);
    }
    
    void addAll(int inc) {
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = (arr[i] + inc) % MOD;
        }
    }
    
    void multAll(int m) {
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = (arr[i] * m) % MOD;
        }
    }
    
    int getIndex(int idx) {
        if (idx >= arr.size()) return -1;
        return arr[idx] % MOD;
    }
};
