class Solution {
    int n,m;
    vector<vector<int>> a,f;
    
    vector<int> x_diff{-1,1,0,0};
    vector<int> y_diff{0,0,-1,1};
    
    bool in_board(int x, int y){
        if (x < 0 || x >= n || y < 0 || y >= m) return false;
        return true;
    }
    
    int solve(int x, int y){
        if (!in_board(x,y)) return 0;
        if (f[x][y] > 0) return f[x][y];
        int next_x, next_y;
        f[x][y] = 1;
        for (int i=0;i<4;++i){
            next_x = x + x_diff[i];
            next_y = y + y_diff[i];
            if (in_board(next_x, next_y) && a[x][y] > a[next_x][next_y]) 
                f[x][y] = max(f[x][y], solve(next_x, next_y) + 1);
        }
        return f[x][y];
    }
    
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        if (n == 0) return 0;
        m = matrix[0].size();
        if (m == 0) return 0;
        
        a = matrix;
        f = vector<vector<int>>(n, vector<int>(m,0));
        int ans = 1;
        for (int i=0;i<n;++i)
            for (int j=0;j<m;++j){
                solve(i,j);
                ans = max(ans, f[i][j]);
            }
        return ans;
    }
};
