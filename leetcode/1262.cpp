class Solution {
public:
    int maxSumDivThree(vector<int>& a) {
        if (a.empty()) return 0;
        int n = a.size();
        vector<vector<int>> f(n, vector<int>(3,0));
        f[0][a[0] % 3] = a[0];
        for (int i=1;i<n;++i){
            vector<int> tmp(3,0);
            for (int j=0;j<3;++j){
                int r = (f[i-1][j] + a[i]) % 3;
                tmp[r] = max(tmp[r], f[i-1][j] + a[i]);
            }
            for (int j=0;j<3;++j)
                f[i][j] = max(f[i-1][j], tmp[j]);
        }
        return f[n-1][0];
    }
};
