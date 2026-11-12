class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size(), ans=1, inc=1, dec=1;
        for(int i=1; i<n; i++){
            inc=(nums[i]>nums[i-1])*inc+1;
            dec=(nums[i]<nums[i-1])*dec+1;
            ans=max(ans, max(inc , dec));
        }
        return ans;
    }
};
