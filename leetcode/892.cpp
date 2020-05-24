class Solution {
    
    int get(vector<vector<int>> &grid, int x, int y){
        if (x < 0 || x >= grid.size()) return 0;
        if (y < 0 || y >= grid[0].size()) return 0;
        return grid[x][y];
    }
    
    int solve(vector<vector<int>> &grid, int x, int y){
        if (grid[x][y] == 0) return 0;
        int result = 2;
        result += max(0, get(grid,x,y) - get(grid,x-1,y));
        result += max(0, get(grid,x,y) - get(grid,x+1,y));
        result += max(0, get(grid,x,y) - get(grid,x,y-1));
        result += max(0, get(grid,x,y) - get(grid,x,y+1));
        return result;
    }
    
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int result = 0;
        for (int i=0;i<n; ++i)
            for (int j=0;j<m;++j)
                result += solve(grid, i, j);
        
        return result;
    }
};
