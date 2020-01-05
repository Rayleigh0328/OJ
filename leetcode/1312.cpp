class Solution {
    
    const int inf = (1<<28);
    
public:
    int minInsertions(string s) {
        // f[i,j], min steps to make s[i..j-1] palindrome
        // f[i,j] = 
        //      f[i, j-1] + 1
        //      f[i+1, j] + 1
        //      f[i+1,j-1] if s[i] == s[j-1]
        // boundary f[x,x] = f[x,x+1] = 0
        
        int n = s.size();
        vector<vector<int>> f(n+1, vector<int>(n+1, inf));
        
        for (int i=0;i<n;++i) f[i][i] = f[i][i+1] = 0;
        
        for (int len = 2; len <= n; ++len)
            for (int i=0; i<n; ++i){
                int j = i + len;
                if (j > n) break;
                if (s[i] == s[j-1])
                    f[i][j] = min(f[i][j], f[i+1][j-1]);
                f[i][j] = min(f[i][j], f[i][j-1] + 1);
                f[i][j] = min(f[i][j], f[i+1][j] + 1);
            }
        
        return f[0][n];
    }
};
