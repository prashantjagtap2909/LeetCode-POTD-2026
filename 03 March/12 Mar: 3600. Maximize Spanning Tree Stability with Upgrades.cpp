class DSU {
private:
    vector<int> rank, parent;

public:
    DSU(int n) {
        rank.resize(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (parent[u] == u)
            return u;
        return parent[u] = find(parent[u]);
    }

    void rankUnion(int u, int v) {

        int parent_u = find(u);
        int parent_v = find(v);

        if (parent_u == parent_v) {
            return;
        }

        if (rank[parent_u] < rank[parent_v]) {
            parent[parent_u] = parent_v;
        } else if (rank[parent_u] > rank[parent_v]) {
            parent[parent_v] = parent_u;
        } else {
            parent[parent_v] = parent_u;
            rank[parent_u]++;
        }
    }
};

class Solution {
public:
    bool check(int n, vector<vector<int>>& edges, int k, int mid) {

        DSU dsu(n);
        vector<vector<int>> upgradeCandidates;

        for (int i = 0; i < edges.size(); i++) { 

            int u = edges[i][0];
            int v = edges[i][1];
            int s = edges[i][2];
            int must = edges[i][3];

            if (must == 1) {
                if (s < mid)
                    return false;

                dsu.rankUnion(u, v);

            } else {
                if (s >= mid) {
                    dsu.rankUnion(u, v);
                } else if (2 * s >= mid) {
                    upgradeCandidates.push_back(vector<int>{u, v});
                }
            }
        }
        for (auto& edge : upgradeCandidates) {
            int u = edge[0];
            int v = edge[1];

            if (dsu.find(u) != dsu.find(v)) {
                if (k <= 0)
                    return false;
                dsu.rankUnion(u, v);
                k--;
            }
        }

        int root = dsu.find(0);
        for (int node = 0; node < n; node++) {
            if (dsu.find(node) != root)
                return false;
        }
        return true;
    }
    int maxStability(int n, vector<vector<int>>& edges, int k) {

        // check earlier that cycle is forming or not
        DSU dsu(n);
        for (auto& edge : edges) {
           
            int u = edge[0], v = edge[1], s = edge[2], must = edge[3];
            // parents are same - cycle is forming
            if (must == 1) {
                if (dsu.find(u) == dsu.find(v)) {
                    return -1;
                }
                dsu.rankUnion(u, v);
            }
        }

        int ans = -1;
        int l = 1, r = 2 * (1e5);

        

        while (l <= r) { // TC -> O(log n)

            int mid = l + (r - l) / 2;

            if (check(n, edges, k, mid)) { // O(n)
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};
