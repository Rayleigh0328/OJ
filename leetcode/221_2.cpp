class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> f(n, vector<int>(m,0));
        for (int i=0; i<n;++i) f[i][0] = (matrix[i][0]=='1'?1:0);
        for (int j=0; j<m;++j) f[0][j] = (matrix[0][j]=='1'?1:0);
        for (int i=1;i<n;++i)
            for (int j=1;j<m;++j)
                if (matrix[i][j]=='1')
                    f[i][j] = 1 + min(min(f[i-1][j-1], f[i-1][j]), f[i][j-1]);
        int ans = 0;
        for (int i=0;i<n;++i)
            for (int j=0;j<m;++j)
                ans = max(ans,f[i][j] * f[i][j]);
        return ans;
    }
};
