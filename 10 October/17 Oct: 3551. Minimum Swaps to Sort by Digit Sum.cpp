class Solution {
public:
     int solve(int v){
        int cnt = 0;
        while(v > 0){
            cnt += v%10;
            v/=10;
        }
        return cnt;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size(),ans=0;
        vector<bool>vis(n,false);
        vector<pair<pair<int,int> , int > >vp;
        for(int i = 0;i<n;i++){
            int v = solve(nums[i]) ;
            vp.push_back({{v,nums[i]} , i});
        }
       sort(vp.begin() , vp.end()) ;

        for(int i = 0;i<n;i++){
            if(i == vp[i].second || vis[i]) continue ;
            int c = 0 , j = i; 
            while(!vis[j]){
                vis[j] = true;
                c++ ;
                j = vp[j].second ;
            }
            ans += (c-1) ;

        }
        return ans;
        
    }
};
