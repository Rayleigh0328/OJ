class Solution {
    
    int n,m;
    
    void shift(vector<vector<int>>& g){
        vector<int> tmp(n);
        for (int i=0;i<n;++i) tmp[i] = g[i][m-1];
        for (int j = m-1; j>0; --j)
            for (int i=0;i<n;++i)
                g[i][j] = g[i][j-1];
        for (int i=1;i<n;++i)
            g[i][0] = tmp[i-1];
        g[0][0] = tmp[n-1];
    }
    
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        if (grid.empty() || grid[0].empty()) return grid;
        n = grid.size();
        m = grid[0].size();
        for (int i=0;i<k;++i) shift(grid);
        return grid;
    }
};
