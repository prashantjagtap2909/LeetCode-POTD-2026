class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& d, vector<int>& walls) {
        int n = robots.size();

        vector<array<int, 2>> x(n);
        for (int i = 0; i < n; i++) {
            x[i] = {robots[i], d[i]};
        }

        sort(x.begin(), x.end());
        sort(walls.begin(), walls.end());
        x.push_back({(int)1e9, 0});

        auto query = [&](int l, int r) -> int {
            if (l > r) return 0;
            auto it1 = upper_bound(walls.begin(), walls.end(), r);
            auto it2 = lower_bound(walls.begin(), walls.end(), l);
            return it1 - it2;
        };

  
        vector<array<int, 2>> dp(n);

        dp[0][0] = query(x[0][0] - x[0][1], x[0][0]);
        if (n > 1) { 
            dp[0][1] = query(
                x[0][0],
                min(x[1][0] - 1, x[0][0] + x[0][1])
            );
        } else {
            dp[0][1] = query(x[0][0], x[0][0] + x[0][1]);
        }

        for (int i = 1; i < n; i++) {
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) +
                       query(
                           x[i][0],
                           min(x[i + 1][0] - 1, x[i][0] + x[i][1])
                       );
            dp[i][0] = dp[i - 1][0] +
                       query(
                           max(x[i][0] - x[i][1], x[i - 1][0] + 1),
                           x[i][0]
                       );
            int leftStart = max(x[i][0] - x[i][1], x[i - 1][0] + 1);
            int leftEnd   = x[i][0];

            int overlapStart = leftStart;
            int overlapEnd   = min(x[i - 1][0] + x[i - 1][1], x[i][0] - 1);
            int res = dp[i - 1][1]
                      + query(leftStart, leftEnd)
                      - query(overlapStart, overlapEnd);

            dp[i][0] = max(dp[i][0], res);
        }
        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};
