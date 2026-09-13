class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();

        vector<pair<int, int>> store;
        set<pair<int, int>> st;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j] == 1) {
                    store.push_back({i, j});
                }

                if (img2[i][j] == 1) {
                    st.insert({i, j});
                }
            }
        }

        int ans = 0;

        for (int dx = -(n - 1); dx <= n - 1; dx++) {
            for (int dy = -(n - 1); dy <= n - 1; dy++) {
                int cnt = 0;

                for (auto [x, y] : store) {
                    int nx = x + dx;
                    int ny = y + dy;

                    if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                        if (st.count({nx, ny})) {
                            cnt++;
                        }
                    }
                }

                ans = max(ans, cnt);
            }
        }

        return ans;
    }
};
