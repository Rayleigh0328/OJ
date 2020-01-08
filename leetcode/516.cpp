class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> f(n, vector<int>(n, 0));
        for (int i=0;i<n;++i) f[i][i] = 1;
        for (int len = 1; len < n; ++len){
            for (int i=0;i<n;++i){
                int j = i + len;
                if (j >= n) break;
                f[i][j] = max(f[i][j], f[i+1][j]);
                f[i][j] = max(f[i][j], f[i][j-1]);
                if (s[i] == s[j])
                    f[i][j] = max(f[i][j], f[i+1][j-1] + 2);
            }
        }
        return f[0][n-1];
    }
};
