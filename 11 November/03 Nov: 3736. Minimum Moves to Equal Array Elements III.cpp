class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxNum = INT_MIN;
        int sum = 0;

        for(int num : nums) {
            sum += num;
            maxNum = max(num, maxNum);
        }

        return nums.size() * maxNum - sum;
    }
};
