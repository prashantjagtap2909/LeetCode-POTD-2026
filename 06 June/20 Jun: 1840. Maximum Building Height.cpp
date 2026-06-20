class Solution {
public:
    void correct(vector<vector<int>>& r) {
        int lasth = 0;
        int lastn = 1;
        for (auto &q : r) {
            int diff = q[0] - lastn;
            q[1] = min(lasth + diff, q[1]);
            lastn = q[0];
            lasth = q[1];
        }
    }

    void correctrev(vector<vector<int>>& r) {
        int n = r.size();

        int lasth = r[n - 1][1];
        int lastn = r[n - 1][0];

        for (int i = n - 2; i >= 0; i--) {
            int diff = lastn - r[i][0];
            r[i][1] = min(lasth + diff, r[i][1]);
            lastn = r[i][0];
            lasth = r[i][1];
        }
    }

    int maxBuilding(int n, vector<vector<int>>& r) {
        r.push_back({1, 0});
        sort(r.begin(), r.end());

        if (r.back()[0] != n) {
            int h = r.back()[1] + (n - r.back()[0]);
            r.push_back({n, h});
        }

        correct(r);
        correctrev(r);

        int ans = 0;

        for (int i = 1; i < r.size(); i++) {

            int s = r[i - 1][0];
            int e = r[i][0];

            int prevh = r[i - 1][1];
            int nxth = r[i][1];

            while (s <= e) {
                int mid = s + (e - s) / 2;
                int diffprev = mid - r[i - 1][0];
                int diffnxt = r[i][0] - mid;

                int midh = min(prevh + diffprev,nxth + diffnxt);
                int mid2 = mid + 1;
                int midh1 = -1;

                if (mid2 <= e) {
                    int diffprev1 = mid2 - r[i - 1][0];
                    int diffnxt1 = r[i][0] - mid2;
                    midh1 = min(prevh + diffprev1,nxth + diffnxt1);
                }
                ans = max(ans, midh);
                
                if (midh1 > midh) s = mid + 1;
                else e = mid - 1;
            }
        }

        return ans;
    }
};
