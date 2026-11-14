class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int sum = INT_MAX;

        for(int start = 0; start <= n-l; start++) {
            int currSum = 0;

            for(int size = 1; size <= r && start + size <= n; size++) {
                currSum += nums[start + size - 1];

                if(size >= l && currSum > 0) {
                    sum = min(sum, currSum);
                }
            }
        }

        return sum == INT_MAX ? -1 : sum;
    }
};
