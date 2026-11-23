class ProductOfNumbers {
public:
    vector<int> pre = {1};

    ProductOfNumbers() {
    }
    
    void add(int num) {
        if (num == 0) {
            pre = {1};
        } else {
            pre.push_back(pre.back() * num);
        }
    }
    
    int getProduct(int k) {
        int n = pre.size();
        if (k >= n) {
            return 0;
        }
        return pre[n - 1] / pre[n - k - 1];
    }
};


