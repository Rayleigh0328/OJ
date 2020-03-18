class Solution {
    const int mode = 1000000007;
public:
    int checkRecord(int n) {
        vector<vector<long long>> f(n+1, vector<long long>(3,0));
        vector<vector<long long>> g(n+1, vector<long long>(3,0));
        f[0][0] = 1;
        for (int i=1;i<=n;++i){
            // P
            f[i][0] += f[i-1][0] + f[i-1][1] + f[i-1][2];
            g[i][0] += g[i-1][0] + g[i-1][1] + g[i-1][2];
            // A
            g[i][0] += f[i-1][0] + f[i-1][1] + f[i-1][2];
            // L
            f[i][1] += f[i-1][0];
            f[i][2] += f[i-1][1];
            g[i][1] += g[i-1][0];
            g[i][2] += g[i-1][1];
            
            f[i][0] %= mode; f[i][1] %= mode; f[i][2] %= mode;
            g[i][0] %= mode; g[i][1] %= mode; g[i][2] %= mode;
        }
        return (f[n][0] + f[n][1] + f[n][2] + g[n][0] + g[n][1] + g[n][2]) % mode;
    }
};
