class Solution {
public:
    void dfs(int u,vector<vector<int>>&adj,vector<int>&vis,vector<int>& s,vector<int>& t,map<int,int>&mp){
        mp[s[u]]++;
        mp[t[u]]--;
        vis[u]=1;
        for(auto it:adj[u]){
            if(!vis[it]){
                dfs(it,adj,vis,s,t,mp);
            }
        }
    }
    int minimumHammingDistance(vector<int>& s, vector<int>& t, vector<vector<int>>& a) {
        int n=s.size();
        vector<vector<int>>adj(n);
        for(auto it:a){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(n);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                map<int,int>mp;
                dfs(i,adj,vis,s,t,mp);
                for(auto [k,w]:mp)ans+=abs(w);
            }
        }return ans/2;
    }
};
