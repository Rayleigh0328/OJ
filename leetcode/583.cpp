class Solution {
    
    int lcs(const string &s, const string &t){
        const int n = s.size();
        const int m = t.size();
        vector<vector<int>> f(n+1, vector<int>(m+1, 0));
        for (int i=1;i<=n;++i)
            for (int j=1;j<=m;++j){
                f[i][j] = max(f[i][j-1],f[i-1][j]);
                if (s[i-1] == t[j-1]) f[i][j] = max(f[i][j], f[i-1][j-1] + 1);
            }
        return f[n][m];
    }
    
public:
    int minDistance(string word1, string word2) {
        int common = lcs(word1, word2);
        return word1.size() + word2.size() - common * 2;
    }
};
