class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();

        // divisors[m] holds all proper divisors of m (d < m and m % d == 0)
        vector<vector<int>> divisors(n + 1);
        for (int d = 1; d < n; d++) {
            for (int m = 2 * d; m <= n; m += d) {
                divisors[m].push_back(d);
            }
        }

        // cost[i][j] = min changes to make s[i..j] a semi-palindrome
        vector<vector<int>> cost(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int len = j - i + 1;
                int best = INT_MAX;
                for (int d : divisors[len]) {
                    int changes = 0;
                    int groupSize = len / d;
                    // handle each residue class modulo d separately
                    for (int r = 0; r < d; r++) {
                        int lo = i + r;
                        int hi = i + r + (groupSize - 1) * d;
                        // compare symmetric characters inside this group
                        while (lo < hi) {
                            if (s[lo] != s[hi]) changes++;
                            lo += d;
                            hi -= d;
                        }
                    }
                    best = min(best, changes);
                }
                cost[i][j] = best;
            }
        }

        // dp[p][j] = min cost to split first p characters into j parts
        const int INF = INT_MAX / 2;
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));
        dp[0][0] = 0;

        for (int j = 1; j <= k; j++) {
            for (int p = 2 * j; p <= n; p++) {
                // last part is s[q..p-1], which must have length >= 2
                for (int q = 2 * (j - 1); q <= p - 2; q++) {
                    if (dp[q][j - 1] < INF) {
                        dp[p][j] = min(dp[p][j], dp[q][j - 1] + cost[q][p - 1]);
                    }
                }
            }
        }
        return dp[n][k];
    }
};
