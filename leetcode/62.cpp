class Solution {
public:
    int uniquePaths(int m, int n) 
    {
        long long **f;
        f = new long long * [n];
        for (int i=0;i<n;++i)
            f[i] = new long long [m];
        for (int i=0;i<n;++i)
            f[i][0] = 1;
        for (int j=0;j<m;++j)
            f[0][j] = 1;
        for (int i=1;i<n;++i)
            for (int j=1;j<m;++j)
                f[i][j] = f[i-1][j] + f[i][j-1];
        return f[n-1][m-1];
    }
};