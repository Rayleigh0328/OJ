class Solution {
public:
    int superEggDrop(int k, int n) {
        // solution 2: f[i][j] use i egg and j move, max floor to decide
        // f[i][j] = f[i-1][j-1] + 1 + f[i][j-1]
        // boundary f[0][j] = 0;
        
        // solution 3: based on solution 2, it is possible to use 1D state
        vector<int> dp(k+ 1, 0);
        int m;
        for (m = 0; dp[k] < n; m++)
            for (int i = k; i > 0; --i)
                dp[i] += dp[i - 1] + 1;
        return m;
    }
};
