class Solution {
public:
    int cal(int a, int b) {
        return abs(a / 6 - b / 6) + abs(a % 6 - b % 6);
    }

    int minimumDistance(string s) {
        int n = s.size();
        vector<int> dp(26), ndp(26);

        for (int i = 1; i < n; i++) {
            int p = s[i - 1] - 'A', t = s[i] - 'A';
            for (int j = 0; j < 26; j++) {
                ndp[j] = dp[j] + cal(p, t);
            }
            for (int j = 0; j < 26; j++) {
                ndp[p] = min(ndp[p], dp[j] + cal(j, t));
            }
            dp = ndp;
        }

        return *min_element(dp.begin(), dp.end());
    }
};
