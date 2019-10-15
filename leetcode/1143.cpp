class Solution {
    int my_max(initializer_list<int> list){
        int result = *list.begin();
        for (auto it = list.begin(); it != list.end(); ++it)
            result = max(*it, result);
        return result;
    }
public:
    int longestCommonSubsequence(string s1, string s2) {
        // f[i][j] lcs of s1[0..i-1] and s2[0..i-1]
        // f[i][j] = max
        //              (s1[i-1] == s2[j-1]?1:0) + f[i-1][j-1]
        //              f[i-1][j]
        //              f[i][j-1]
        // boundary f[0][j] = f[i][0] = 0;
        
        int n = s1.length();
        int m = s2.length();
        int f[n+1][m+1];
        memset(f, 0, sizeof f);
        for (int i=1;i<=n;++i)
            for (int j=1;j<=m;++j)
                f[i][j] = my_max({
                    (s1[i-1]==s2[j-1]?1:0) + f[i-1][j-1],
                    f[i-1][j],
                    f[i][j-1]
                });
        return f[n][m];
    }
};
