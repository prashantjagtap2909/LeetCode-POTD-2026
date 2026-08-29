class Solution {
public:
    vector<int>parent,s;
    void start(int n){
        parent.resize(n);
        s.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }

    int get(int node){
       if(parent[node]==node){
        return node;
       }

       return parent[node]=get(parent[node]);
    }

    void dsu(int u,int v){
        int pu=get(u);
        int pv=get(v);
        if(pu==pv) return;

        if(s[pu]<s[pv]){
            parent[pu]=pv;
            s[pv]+=s[pu];
        }
        else{
            parent[pv]=pu;
            s[pu]+=s[pv];
        }
    }
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<pair<int,int>>arr(n);
        for(int i=0;i<n;i++){
            arr[i]={nums[i],i};
        }

        sort(arr.begin(),arr.end());
        start(n);
        for(int i=0;i<n-1;i++){
            if(arr[i+1].first-arr[i].first<=limit){
                dsu(arr[i+1].second,arr[i].second);
            }
        }

        map<int,vector<int>>mp;
        map<int,vector<int>>mpp;

        for(int i=0;i<n;i++){
            mp[get(i)].push_back(i);
        }
        for(int i=0;i<n;i++){
            mpp[get(i)].push_back(nums[i]);
        }
         for(auto &it:mp){
            sort(it.second.begin(),it.second.end());
        }
        for(auto &it:mpp){
            sort(it.second.begin(),it.second.end());
        }
        vector<int>ans(n);
        for(auto it:mp){
            vector<int>temp=it.second;
            int i=0;
            for(auto x:mpp[it.first]){
                ans[temp[i]]=x;
                i++;
            }
        }
        

        return ans;
    }
};
