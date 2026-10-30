class Solution {
public:
    using T = tuple<int,int,int>;
    static inline vector<vector<int>>dist;
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto &i : edges){
            adj[i[0]].push_back({i[1],i[2]});
        }
        priority_queue<T,vector<T>,greater<T>>pq;
        dist.assign(n, vector<int>(k + 1, INT_MAX));
        pq.push({0,0,1});
        dist[0][1] = 0;
        while(!pq.empty()){
            auto [dis,node,p_streak] = pq.top();
            pq.pop();
            if(node == n - 1){
                return dis;
            }
            for(auto[dst,cst] : adj[node]){
                int n_streak = (labels[node] == labels[dst])?p_streak + 1:1;
                if(n_streak <= k && dist[dst][n_streak] > dis + cst){
                    dist[dst][n_streak] = dis + cst;
                    pq.push({dis + cst,dst,n_streak});
                }
            }
        }
        return -1;
    }
};
