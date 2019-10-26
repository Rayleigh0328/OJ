class Solution {
    
    bool solve(const string& s1, int i, const string &s2, int j, const string &s3, vector<vector<int>>& f){
        if (i < 0 || j < 0) return false;
        if (f[i][j] != -1) return f[i][j];
        bool result = false;
        if (i>0 && s3[i+j-1] == s1[i-1]) result = result || solve(s1,i-1,s2,j,s3,f);
        if (j>0 && s3[i+j-1] == s2[j-1]) result = result || solve(s1,i,s2,j-1,s3,f);
        return (f[i][j] = result);
    }
    
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length();
        int m = s2.length();
        if (s3.length() != n + m) return false;
        vector<vector<int>> f(n+1, vector<int>(m+1, -1));
        f[0][0] = 1;
        return solve(s1,n, s2,m, s3, f);
    }
};
