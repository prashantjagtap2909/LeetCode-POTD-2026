class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int mod=1e9+7;
        for(auto &q:queries){
            int idx=q[0];
            while(idx<=q[1] && idx<n){
                nums[idx] = (int)(((long long)nums[idx] * q[3]) % mod);
                idx+=q[2];
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=ans ^ nums[i];
        }
        return ans;
    }
};
