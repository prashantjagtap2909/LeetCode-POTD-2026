class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minNum = INT_MAX;

        for(int n : nums) {
            minNum = min(minNum, n);
        }

        int count = 0;

        for(int n : nums) {
            count += n - minNum;
        }

        return count;
    }
};
