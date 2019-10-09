class Solution {
    long long mode = 1000000007;
public:
    int numMusicPlaylists(int n, int l, int k) {
        vector<vector<long long>> f(n+1, vector<long long>(l+1,0));
        f[0][0] = 1;
        for (int i=1;i<=n;++i)
            for (int j=1;j<=l;++j){
                f[i][j] = (f[i-1][j-1] + (i>k?f[i][j-1] * (i-k):0) ) % mode;
            }
        long long ans = f[n][l];
        for (int i=1;i<=n;++i){
            ans = (ans * i) % mode;
        }
        return (int)ans;
    }
};
