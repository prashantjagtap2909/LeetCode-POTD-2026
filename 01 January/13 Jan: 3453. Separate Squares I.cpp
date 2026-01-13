class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double lo = 1e18, hi = -1e18;
        double total = 0.0;
        for (auto &s : squares) {
            lo = min(lo, (double)s[1]);
            hi = max(hi, (double)s[1] + s[2]);
            total += (double)s[2] * s[2];
        }
        double target = total / 2.0;
        for (int it = 0; it < 80; it++) {
            double mid = (lo + hi) / 2.0;
            double below = 0.0;
            for (auto &s : squares) {
                double y = s[1], l = s[2];
                if (mid <= y) continue;
                double h = min(mid - y, l);
                below += h * l;
            }
            if (below < target) lo = mid;
            else hi = mid;
        }
        return lo;
    }
};
