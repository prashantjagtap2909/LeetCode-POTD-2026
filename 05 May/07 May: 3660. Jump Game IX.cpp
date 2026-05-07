const int N=1e5;
int prefMax[N];
class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n=nums.size();
        prefMax[0]=nums[0];
        for(int i=1; i<n; i++){
            const int x=nums[i];
            prefMax[i]=max(prefMax[i-1], x);
        }
        vector<int> ans(n);
        ans[n-1]=prefMax[n-1];
        int sufMin=nums[n-1];
        for(int i=n-2; i>=0; i--){
            if (prefMax[i]>sufMin) 
                ans[i]=ans[i+1];
            else ans[i]=prefMax[i];
            sufMin=min(sufMin, nums[i]);
        }
        return ans;
    }
};
