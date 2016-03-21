class Solution {
private:
    const int inf =  1 << 30;
    int get_value(int x, int y, int** f, int n, int m)
    {
        if (x < 0 || x >=n) return inf;
        if (y < 0 || y >=m) return inf;
        return f[x][y];
    }
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        if (grid.empty()) return 0;
        
        int n = grid.size();
        int m = grid[0].size();
        
        int **f = new int* [n];
        for (int i=0;i<n;++i)
            f[i] = new int [m];
        
        for (int i=0;i<n;++i)
            for (int j=0;j<m;++j)
            {
                if (i == 0 && j == 0) f[i][j] = grid[i][j];
                else
                    f[i][j] = min(get_value(i-1,j,f,n,m), get_value(i,j-1,f,n,m)) + grid[i][j];
            }
        
        int ans = f[n-1][m-1];
        for (int i=0;i<n;++i)
            delete [] f[i];
        delete [] f;
        return ans;
    }
};