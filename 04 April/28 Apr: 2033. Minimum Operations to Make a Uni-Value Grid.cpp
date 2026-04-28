class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        const int m = grid.size(), n = grid[0].size(), N = m * n;
        int freq[10001] = {0}, xMin = INT_MAX, xMax = 0;

        int r = grid[0][0] % x;
        for (const auto& row : grid) {
            for (int num : row) {
                auto [q, rr] = div(num, x);
                if (rr != r)
                    return -1; 
                freq[q]++;  
                xMax=max(xMax, q);
                xMin=min(xMin, q);
    }
};
