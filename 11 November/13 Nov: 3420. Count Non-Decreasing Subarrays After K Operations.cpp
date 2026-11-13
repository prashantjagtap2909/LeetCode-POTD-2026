
class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), j = n - 1;
        long long ans = 0, cost = 0;
        deque<pair<int, int>> dq;

        for (int i = n - 1; i >= 0; i--) {
            int cnt = 1;
            while (!dq.empty() && dq.back().first < nums[i]) {
                auto [v, c] = dq.back();
                dq.pop_back();
                cnt += c;
                cost += 1LL * (nums[i] - v) * c;
            }
            dq.push_back({nums[i], cnt});
            while (cost > k) {
                auto [v, c] = dq.front();
                dq.pop_front();
                cost -= v - nums[j--];
                if (--c) dq.push_front({v, c});
            }
            ans += j - i + 1;
        }
        return ans;
    }
};
