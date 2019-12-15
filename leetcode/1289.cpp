class Solution {
    const int inf = (1<<28);
public:
    int minFallingPathSum(vector<vector<int>>& a) {
        if (a.empty() || a[0].empty()) return 0;
        int n = a.size();
        int m = a[0].size();
        vector<vector<int>> f(n, vector<int>(m,inf));
        for (int j=0;j<m;++j) f[0][j] = a[0][j];
        for (int i=1;i<n;++i)
            for (int j=0;j<m;++j)
                for (int k=0;k<m;++k)
                    if (k != j) 
                        f[i][j] = min(f[i][j], f[i-1][k] + a[i][j]);
        int result = inf;
        for (int j=0;j<m;++j)
            result = min(result, f[n-1][j]);
        return result;
    }
};
