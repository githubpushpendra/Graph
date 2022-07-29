/** Problem link 
*   https://leetcode.com/problems/number-of-islands/
**/

// Soluiton

class Solution {
public:
    
    void dfs(vector<vector<char>>& grid, int i, int j)
    {
        int m = grid.size();
        int n = grid[0].size();
        if(i<0 || j<0) return;
        if(i>=m || j>=n) return;
        if(grid[i][j] != '1') return;
        grid[i][j] = '0';
        dfs(grid, i, j-1);
        dfs(grid, i, j+1);
        dfs(grid, i-1, j);
        dfs(grid, i+1, j);
        return;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int ct=0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '1'){
                    ct++;
                    dfs(grid, i, j);
                    
                }
            }
        }
        return ct;
    }
};