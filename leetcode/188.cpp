class Solution {
    const int inf = (1<<28);
public:
    int maxProfit(int k, vector<int>& p) {
        // f[i][j] at the end of day i, hold NO stock, sell j times
        // g[i][j] at the end of day i, hold one stock, sell j times
        // f[i][j] = max{ f[i-1][j] , g[i-1][j-1] + p[i] }
        // g[i][j] = max{ g[i-1][j] , f[i-1][j] - p[i]}
        // boundary f[0][0] = 0 , g[0][0] = -p[0]
        
        if (p.size() == 0) return 0;
        
        int n = p.size();
        if (k > (n+1)/2) k = (n+1)/2; 
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
