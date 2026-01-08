class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        
        vector<vector<int>> dp(n, vector<int>(m));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int product = nums1[i] * nums2[j];
                dp[i][j] = product;
                if (i > 0 && j > 0) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1] + product);
                }
                if (i > 0) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j]);
                }
                if (j > 0) {
                    dp[i][j] = max(dp[i][j], dp[i][j-1]);
                }
            }
        }

        return dp[n-1][m-1];
    }
};
