class Solution {
public:
    int n, m;

    bool checkHz(vector<vector<int>> grid){
        unordered_set<long long> st;

        long long pref = 0;

        for(int i=0; i<n; i++){
            long long rowSum = 0;
            for(int j=0; j<m; j++){
                rowSum += grid[i][j];
            }
            pref += rowSum;
            st.insert(pref);
        }

        if(pref % 2 != 0) return false;

        return st.count(pref / 2);
    }

    bool checkVz(vector<vector<int>> grid){
        unordered_set<long long> st;

        long long pref = 0;

        for(int j=0; j<m; j++){
            long long colSum = 0;
            for(int i=0; i<n; i++){
                colSum += grid[i][j];
            }
            pref += colSum;
            st.insert(pref);
        }

        if(pref % 2 != 0) return false;

        return st.count(pref / 2);
    }

    bool canPartitionGrid(vector<vector<int>>& grid) {
        this->n = grid.size();
        this->m = grid[0].size();

        return checkHz(grid) || checkVz(grid);
    }
};
