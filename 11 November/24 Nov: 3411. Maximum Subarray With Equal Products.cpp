class Solution {
private:
    long long gcd(long long a, long long b) {
        while (b) {
            long long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }

public:
    int maxLength(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        int max_len = 0;
        for (int i = 0; i < n; i++) {
            long long current_prod = 1;
            long long current_gcd = nums[i];
            long long current_lcm = nums[i];

            for (int j = i; j < n; j++) {
                if (current_prod > 1000000000000LL / nums[j]) {
                    current_prod = 2000000000000LL;
                } else {
                    current_prod *= nums[j];
                }

                if (j > i) {
                    current_gcd = gcd(current_gcd, nums[j]);
                    current_lcm = lcm(current_lcm, nums[j]);
                }

                if (current_prod == current_lcm * current_gcd) {
                    max_len = max(max_len, j - i + 1);
                }
            }
        }
        return max_len;
    }
};
