class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<pair<int, int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        int d = 0;
        int x = 0, y = 0;
        int res = 0;

        set<pair<int,int>> hash_set;
        for (auto& o : obstacles) {
            hash_set.insert({o[0], o[1]});
        }

        for (int c : commands) {
            if (c == -2) {
                d = (d + 3) % 4;
            } else if (c == -1) {
                d = (d + 1) % 4;
            } else {
                for (int i = 0; i < c; i++) {
                    int ox = x + dirs[d].first;
                    int oy = y + dirs[d].second;
                    if (hash_set.count({ox, oy})) 
                        break;
                    x = ox;
                    y = oy;
                    res = max(res, x * x + y * y);
                }
            }
        }

        return res;
    }
};
