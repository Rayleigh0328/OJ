class Solution {
public:
    int minSteps(int n) {
        const int inf = (1<<30);
        vector<vector<int>> f(n+1,vector<int>(n+1, inf));
        f[1][0] = 0;
        for (int i=1;i<=n;++i)
            for (int j=0;j<=i;++j){
                f[i][i] = min(f[i][i], f[i][j] + 1);
                if (i+j<=n) f[i+j][j] = min(f[i+j][j], f[i][j] + 1);
            }
        
        int result = inf;
        for (int j=0;j<=n;++j)
            result = min(result, f[n][j]);
        return result;
    }
};
