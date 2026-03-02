class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size(), res = 0;
        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            int j = n - 1, cnt = 0;
            while (j >= 0 && grid[i][j] == 0) { cnt++; j--; }
            a[i] = cnt;
        }

        for (int i = 0; i < n; i++) {
            if (a[i] < n - 1 - i) {
                int j = i;
            
                while (j < n && a[j] < n - 1 - i) j++;
                if (j == n) return -1; 
              
                while (i < j) {
                    swap(a[j], a[j - 1]);
                    res++;
                    j--;
                }
            }
        }
        return res;
    }
};
