class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        vector<vector<int>> g(n);

        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector<int> parent(n, -1), depth(n), order{0};
        parent[0] = 0;

        for (int i = 0; i < (int)order.size(); ++i) {
            int u = order[i];

            for (int v : g[u]) {
                if (v != parent[u]) {
                    parent[v] = u;
                    depth[v] = depth[u] + 1;
                    order.push_back(v);
                }
            }
        }

        vector<int> size(n, 1), heavy(n, -1);

        for (int i = n - 1; i > 0; --i) {
            int u = order[i];
            int p = parent[u];

            size[p] += size[u];

            if (heavy[p] == -1 || size[u] > size[heavy[p]]) {
                heavy[p] = u;
            }
        }

        vector<int> head(n), pos(n);
        vector<pair<int, int>> stack{{0, 0}};
        int cur = 0;

        while (!stack.empty()) {
            auto [u, h] = stack.back();
            stack.pop_back();

            while (u != -1) {
                head[u] = h;
                pos[u] = cur++;

                for (int v : g[u]) {
                    if (v != parent[u] && v != heavy[u]) {
                        stack.emplace_back(v, v);
                    }
                }

                u = heavy[u];
            }
        }

        int size2 = 1;
        while (size2 < n) size2 <<= 1;

        vector<int> seg(2 * size2);

        for (int u = 0; u < n; ++u) {
            seg[size2 + pos[u]] = 1 << (s[u] - 'a');
        }

        for (int i = size2 - 1; i > 0; --i) {
            seg[i] = seg[i * 2] ^ seg[i * 2 + 1];
        }

        auto update = [&](int p, int value) {
            p += size2;
            seg[p] = value;

            for (p >>= 1; p; p >>= 1) {
                seg[p] = seg[p * 2] ^ seg[p * 2 + 1];
            }
        };

        auto rangeQuery = [&](int l, int r) {
            l += size2;
            r += size2;
            int res = 0;

            while (l <= r) {
                if (l & 1) res ^= seg[l++];
                if (!(r & 1)) res ^= seg[r--];

                l >>= 1;
                r >>= 1;
            }

            return res;
        };

        auto pathQuery = [&](int u, int v) {
            int res = 0;

            while (head[u] != head[v]) {
                if (depth[head[u]] < depth[head[v]]) {
                    swap(u, v);
                }

                res ^= rangeQuery(pos[head[u]], pos[u]);
                u = parent[head[u]];
            }

            if (depth[u] > depth[v]) swap(u, v);

            return res ^ rangeQuery(pos[u], pos[v]);
        };

        vector<bool> ans;

        for (const string& q : queries) {
            istringstream in(q);
            string type;
            int u;

            in >> type >> u;

            if (type == "update") {
                char c;
                in >> c;
                update(pos[u], 1 << (c - 'a'));
            } else {
                int v;
                in >> v;
                int mask = pathQuery(u, v);
                ans.push_back((mask & (mask - 1)) == 0);
            }
        }

        return ans;
    }
};
