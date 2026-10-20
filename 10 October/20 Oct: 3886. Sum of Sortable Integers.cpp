class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for (int k = 1; k <= n; k++) {
            if (n % k) continue;
            bool ok = true;
            int prevMax = 0;
            for (int base = 0; base < n; base += k) {
                int desc = 0;
                int mn = nums[base], mx = nums[base];
                for (int j = 0; j < k; j++) {
                    int a = nums[base + j];
                    int b = nums[base + (j + 1) % k];
                    if (a > b) desc++;
                    mn = min(mn, a);
                    mx = max(mx, a);
                }
                if (desc > 1 || prevMax > mn) {
                    ok = false;
                    break;
                }
                prevMax = mx;
            }
            if (ok) total += k;
        }
        return total;
    }
};
