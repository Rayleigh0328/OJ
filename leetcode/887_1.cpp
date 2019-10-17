class Solution {
public:
    int superEggDrop(int k, int n) {
        // solution 2: f[i][j] use i egg and j move, max floor to decide
        // f[i][j] = f[i-1][j-1] + 1 + f[i][j-1]
        // boundary f[0][j] = 0;
        vector<vector<int>> f(k+1, vector<int>(n+1, 0));
        for (int j=1;j<=n;++j){
            for (int i=1; i<=k; ++i)
                f[i][j] = f[i-1][j-1] + f[i][j-1] + 1;
            if (f[k][j] >= n) return j;
        }
        return 0;
    }
};
