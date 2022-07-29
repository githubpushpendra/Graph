/** Problem Link
*   https://leetcode.com/problems/flood-fill/
**/

// Soluiton

class Solution {
    
    
public:
    
    void dfs(vector<vector<int>>& image, int i, int j, int color, int incolor)
    {
        int m = image.size();
        int n = image[0].size();
        
        if(i<0 || j<0) return;
        if(i>=m || j>=n) return;
        if(image[i][j] != incolor) return;
        
        image[i][j] = color;
        
        dfs(image, i,j-1, color, incolor);
        dfs(image, i,j+1, color, incolor);
        dfs(image, i-1,j, color, incolor);
        dfs(image, i+1,j, color, incolor);
        
        return;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(color != image[sr][sc]) dfs(image, sr, sc, color, image[sr][sc]);
        return image;
    }
};