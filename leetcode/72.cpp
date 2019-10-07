class Solution {
    int INF = (1 << 30);
public:
    int minDistance(string a, string b) {
        // f[i,j] : match a's prefix of length i and b's prefix with length j
        // boundary :
        //      f[0,0] = 0; f[x,0] = x for len(a) >= x > 0 
        //      f[0,x] = x for len(b) >= x > 0
        // f[i,j] = min{ 
        //      f[i-1, j-1] + 1     : replace
        //      f[i, j-1] + 1       : insert
        //      f[i-1, j] +1        : delete
        //      f[i-1, j-1]         : equal
        
        int n = a.length();
        int m = b.length();
        
        vector<vector<int>> f(n+1, vector<int>(m+1, INF));
        for (int i=0; i<=n; ++i) f[i][0] = i;
        for (int i=0; i<=m; ++i) f[0][i] = i;
        
        for (int i=1;i<=n;++i)
            for (int j=1;j<=m;++j){
                f[i][j] = min(f[i][j], f[i-1][j-1] + (a[i-1]==b[j-1]?0:1) );
                f[i][j] = min(f[i][j], f[i][j-1] + 1);
                f[i][j] = min(f[i][j], f[i-1][j] + 1);
            } 
        return f[n][m];
    }
};
