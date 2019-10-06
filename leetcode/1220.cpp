class Solution {
    long long mode = 1000000007;
public:
    int countVowelPermutation(int n) {
        // 0 --> a
        // 1 --> e
        // 2 --> i
        // 3 --> o
        // 4 --> u
        
        vector<vector<long long>> f(n+1, vector<long long>(5,0ll));
        for (int i=0;i<5;++i) f[1][i] = 1;
        for (int i=2;i<=n;++i){
            f[i][0] = (f[i-1][1] + f[i-1][2] + f[i-1][4]) % mode;
            f[i][1] = (f[i-1][0] + f[i-1][2]) % mode;
            f[i][2] = (f[i-1][1] + f[i-1][3]) % mode;
            f[i][3] = (f[i-1][2]);
            f[i][4] = (f[i-1][2] + f[i-1][3]) % mode;
        }
        
        long long ans = 0ll;
        for (int i=0;i<5;++i)
            ans += f[n][i];
        return (int) (ans%mode);
    }
};
