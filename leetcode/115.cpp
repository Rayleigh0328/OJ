class Solution {
public:
    int numDistinct(string s, string t) {
        // f[i][j], ways to match prefix s(0..i-1) with prefix t(0..j-1)
        // sepcially define f[x][0] = 1
        // if s[i-1] == t[j-1] then f[i][j] = f[i-1][j] + f[i-1][j-1]
        // else f[i][j] = f[i-1][j]
        
        int n = s.length();
        int m = t.length();
        vector<vector<long long>> f(n+1, vector<long long>(m+1, 0ll));
        for (int i=0;i<=n;++i) f[i][0] = 1ll;
        for (int i=1;i<=n;++i)
            for (int j=1;j<=m;++j)
                if (s[i-1] == t[j-1]) 
                    f[i][j] = f[i-1][j] + f[i-1][j-1];
                else
                    f[i][j] = f[i-1][j];
        return f[n][m];
    }
};
