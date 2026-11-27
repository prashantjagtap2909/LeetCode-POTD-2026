class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = static_cast<int>(items.size());
        vector<int> bonus(n, 0);
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                if (i != j && items[j][0] % items[i][0] == 0) {
                    ++cnt;
                }
            }
            bonus[i] = cnt;
        }

        vector<int> dp(budget + 1, 0);
        for (int i = 0; i < n; ++i) {
            int cost = items[i][1];
            int freeCopies = bonus[i];
            if (cost <= budget) {
                for (int b = budget; b >= cost; --b) {
                    dp[b] = max(dp[b], dp[b - cost] + 1 + freeCopies);
                }
                for (int b = cost; b <= budget; ++b) {
                    dp[b] = max(dp[b], dp[b - cost] + 1);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};
