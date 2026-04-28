class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        int res = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                nums.push_back(grid[i][j]);
            }
        }

        int len = nums.size();
        nth_element(nums.begin(), nums.begin() + len / 2, nums.end());
        int target = nums[len / 2];

        for (int n : nums) {
            if (n % x != target % x) return -1;
            res += abs(target - n) / x;
        }

        return res;
    }
};
