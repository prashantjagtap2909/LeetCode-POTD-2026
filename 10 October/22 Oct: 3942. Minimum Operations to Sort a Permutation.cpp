class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), a = nums[0];
        int ans = INT_MAX;
        bool asc = true, desc = true;

        for (int i = 0; i < n; i++) {
            if (nums[i] != (a + i) % n) asc = false;
            if (nums[i] != ((a - i) % n + n) % n) desc = false;
        }

        if (asc) ans = (a == 0) ? 0 : min(n - a, a + 2);
        if (desc) {
            int k = (a + 1) % n;
            ans = min({ans, 1 + (n - k) % n, k + 1});
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
