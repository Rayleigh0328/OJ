class Solution {
    
    const int inf = (1<<28);
    
public:
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        const int n = a.size();
        const int m = b.size();
        
        vector<vector<int>> f(n+1, vector<int>(m+1, -inf));
        
        f[0][0] = a[0] * b[0];
        for (int j=1;j<m;++j)
            f[0][j] = max(f[0][j-1], a[0]*b[j]);
        for (int i=1;i<n;++i)
            f[i][0] = max(f[i-1][0], a[i]*b[0]);
        
        for (int i=1;i<n;++i)
            for (int j=1;j<m;++j){
                f[i][j] = max(f[i][j], a[i] * b[j]);
                f[i][j] = max(f[i][j], f[i-1][j-1] + a[i] * b[j]);
                f[i][j] = max(f[i][j], f[i-1][j-1]);
                f[i][j] = max(f[i][j], f[i-1][j]);
                f[i][j] = max(f[i][j], f[i][j-1]);
            }
        
        return f[n-1][m-1];
    }
};
