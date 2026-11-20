class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        unordered_map<int, int>dp;
        int ans = 1;

        for(auto u:nums) {
            dp[u+1] = max(dp[u+1], dp[u]+1);
            dp[u] = max(dp[u], dp[u-1]+1);

            ans = max({ans, dp[u], dp[u+1]});
        }

        return ans;
    }
};
