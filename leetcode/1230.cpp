class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        // dp[i][j] means the toss first i coin, j head and i-j tail (0<=j<=i)
        // dp[1][0] = 1-prob[0], dp[1][1] = prob[0];
        // f[i][0] = f[i-1][0] * (1-prob[i-1])
        // f[i-1][j] = f[i-1][j-1] * prob[i-1] + f[i-1][j];
        // ans is in f[n][target]
        
        int n = prob.size();
        vector<vector<double>> f(n+1, vector<double>(n+1,0));
        f[1][0] = (1-prob[0]);
        f[1][1] = prob[0];
        for (int i=2;i<=n;++i){
            f[i][0] = f[i-1][0] * (1-prob[i-1]);
            for (int j=1;j<=i;++j)
                f[i][j] = f[i-1][j-1] * prob[i-1] + f[i-1][j] * (1-prob[i-1]);
        }
        return f[n][target];
    }
};
