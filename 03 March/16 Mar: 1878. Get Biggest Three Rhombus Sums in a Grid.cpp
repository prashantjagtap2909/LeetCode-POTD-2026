class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        set<int> sums;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                sums.insert(grid[i][j]);

                int k = 1;
                while (true) {
                    if (i - k < 0 || i + k >= m || j - k < 0 || j + k >= n)
                        break;

                    int total = 0;

                    for (int t = 0; t < k; t++)
                        total += grid[i - k + t][j + t];

                    for (int t = 0; t < k; t++)
                        total += grid[i + t][j + k - t];

                    for (int t = 0; t < k; t++)
                        total += grid[i + k - t][j - t];

                    for (int t = 0; t < k; t++)
                        total += grid[i - t][j - k + t];

                    sums.insert(total);
                    k++;
                }
            }
        }

        vector<int> result(sums.begin(), sums.end());
        sort(result.rbegin(), result.rend());

        if (result.size() > 3)
            result.resize(3);

        return result;
    }   
};
