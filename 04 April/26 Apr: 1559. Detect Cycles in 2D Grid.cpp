class Solution {
public:
    int dfs(int i, int j, int pi, int pj,
            vector<vector<char>>& grid,
            vector<vector<int>>& isvisited,
            int r , int c){

        isvisited[i][j] = 1;

        // up
        if((i-1)>=0 && grid[i-1][j] == grid[i][j]){
            if(isvisited[i-1][j] == 0){
                if(dfs(i-1, j, i, j, grid, isvisited, r , c)) return 1;
            }
            else if(i-1 != pi || j != pj){
                return 1;
            }
        }

        // down
        if((i+1)<r && grid[i+1][j] == grid[i][j]){
            if(isvisited[i+1][j] == 0){
                if(dfs(i+1, j, i, j, grid, isvisited, r , c)) return 1;
            }
            else if(i+1 != pi || j != pj){
                return 1;
            }
        }

        // left
        if((j-1)>=0 && grid[i][j-1] == grid[i][j]){
            if(isvisited[i][j-1] == 0){
                if(dfs(i, j-1, i, j, grid, isvisited, r , c)) return 1;
            }
            else if(i != pi || j-1 != pj){
                return 1;
            }
        }

        // right
        if((j+1)<c && grid[i][j+1] == grid[i][j]){
            if(isvisited[i][j+1] == 0){
                if(dfs(i, j+1, i, j, grid, isvisited, r , c)) return 1;
            }
            else if(i != pi || j+1 != pj){
                return 1;
            }
        }


        return 0;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = grid[0].size();

        vector<vector<int>> isvisited(rows, vector<int>(cols, 0));

        for(int i=0; i<rows ; i++){
            for(int j=0; j<cols; j++){
                if(isvisited[i][j]==0){
                   int temp = dfs(i, j, -1, -1, grid, isvisited, rows, cols);
                   if(temp == 1){
                        return true;
                   }
                }
            }
        }
        return false;
    }
};
