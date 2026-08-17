class Solution {
public:
    int game(vector<vector<int>>& dp, vector<int>& a,
             int i, int j, int total) {

        if (i >= j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;
        int sumTillK = 0;

        for (int k = i; k < j; k++) {

            sumTillK += a[k];

            int sumAfterK = total - sumTillK;

            if (sumTillK > sumAfterK) {

                ans = max(ans,
                    sumAfterK +
                    game(dp, a, k + 1, j, sumAfterK));

            } else if (sumTillK < sumAfterK) {

                ans = max(ans,
                    sumTillK +
                    game(dp, a, i, k, sumTillK));

            } else {

                ans = max(ans,
                    sumTillK +
                    max(
                        game(dp, a, k + 1, j, sumAfterK),
                        game(dp, a, i, k, sumTillK)
                    ));
            }
        }

        return dp[i][j] = ans;
    }

    int stoneGameV(vector<int>& stoneValue) {

        int n = stoneValue.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        int totalSum = accumulate(
            stoneValue.begin(),
            stoneValue.end(),
            0
        );

        return game(dp, stoneValue, 0, n - 1, totalSum);
    }
};
