class Solution {
    const int inf = (1<<29);
public:
    int maxProfit(vector<int>& p) {
        if (p.size() == 0) return 0;
        
        int n = p.size();
        int k = 2;
        vector<vector<int>> f(n, vector<int>(k+1, -inf));
        vector<vector<int>> g(n, vector<int>(k+1, -inf));
        
        f[0][0] = 0;
        g[0][0] = -p[0];
        for (int i=1; i<n; ++i)
            for (int j=0;j<=k;++j){
                f[i][j] = f[i-1][j];
                if (j > 0) f[i][j] = max(f[i][j], g[i-1][j-1] + p[i]);
                
                g[i][j] = max(g[i-1][j], f[i-1][j] - p[i]);
            }
        
        int ans = 0;
        for (int i=0;i<=k;++i)
            ans = max(ans, f[n-1][i]);
        return ans;
    }
};
