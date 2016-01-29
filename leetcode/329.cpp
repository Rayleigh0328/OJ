class Solution {
public:
    struct pos{
        int x, y, v;
        pos(int a, int b, int c)
        {
            x = a;
            y = b;
            v = c;
        }
        bool operator<(const pos &other) const
        {
            return v<other.v;
        }
    };
    
    int solve(int r, int c, vector<vector<int>>& matrix, int n, int m, int** f)
    {
        if (r != 0 && matrix[r-1][c]<matrix[r][c]) f[r][c] = max(f[r][c], f[r-1][c] + 1);
        if (r != n-1 && matrix[r+1][c]<matrix[r][c]) f[r][c] = max(f[r][c], f[r+1][c] + 1);
        
        if (c != 0 && matrix[r][c-1]<matrix[r][c]) f[r][c] = max(f[r][c], f[r][c-1]+1);
        if (c != m-1 && matrix[r][c+1]<matrix[r][c]) f[r][c] = max(f[r][c], f[r][c+1]+1);
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0; 
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<pos> a;
        a.clear();
        for (int i=0; i<n; ++i)
            for (int j=0;j<m; ++j)
                a.push_back(pos(i,j,matrix[i][j]));
        sort(a.begin(), a.end());
        
        int **f = new int* [n];
        for (int i=0;i<n;++i)
            f[i] = new int [m];
        for (int i=0;i<n;++i)
            for (int j=0;j<m;++j)
                f[i][j] = 1;
        
        for (int i=0;i<a.size();++i)
            solve(a[i].x, a[i].y,matrix, n, m, f);
        
        int ans = 0;
        for (int i=0;i<n;++i)
            for (int j=0;j<m;++j)
                ans = max(ans, f[i][j]);
        return ans;
    }
};