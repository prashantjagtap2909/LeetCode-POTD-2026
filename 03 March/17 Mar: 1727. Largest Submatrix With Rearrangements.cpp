class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int maxArea = 0;

        for (int r = 0; r < rows; r++) {

            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1 && r > 0) {
                    grid[r][c] += grid[r - 1][c];
                }
            }

            vector<int> heights = grid[r];
            sort(heights.begin(), heights.end());

            for (int i = cols - 1; i >= 0; i--) {
                int width = cols - i;
                int area = heights[i] * width;
                maxArea = max(maxArea, area);
            }
        }

        return maxArea;
    }
};
