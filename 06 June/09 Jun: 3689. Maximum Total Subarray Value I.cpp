class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        auto [m, M]=ranges::minmax(nums);
        return (long long)k*(M-m);
    }
};
