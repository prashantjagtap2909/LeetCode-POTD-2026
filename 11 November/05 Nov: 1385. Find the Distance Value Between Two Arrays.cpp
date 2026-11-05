class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans=0;
        sort(arr2.begin(),arr2.end());
        for(auto &x:arr1){
            int l=x-d;
            int r=x+d;
            // if [l,r] exist in arr2 then x is not the ans,else it is
            int ind1  = lower_bound(arr2.begin(),arr2.end(),l) - arr2.begin();
            int ind2  = lower_bound(arr2.begin(),arr2.end(),r) - arr2.begin();

            if( (ind1==ind2) and (arr2[ind1] !=l and arr2[ind1]!=r)) ans++;
        }
        return ans;
    }
};
