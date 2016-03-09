class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.length() != s2.length()) return false;
        int len = s1.length();
        
        bool f[len][len][len];
        
        for (int i=0;i<len;++i)
            for (int j=0;j<len;++j)
                for (int k=0;k<len;++k)
                    f[i][j][k] = false;
                    
        for (int i=0;i<len;++i)
            for (int j=0;j<len;++j)
                if (s1[i] == s2[j]) f[i][j][0] = true;
        
        //compare [i,i+diff] with [j, j+diff], use k to partition interval
        for (int diff = 1; diff<len;++diff)
            for (int i=0;i+diff<len;++i)
                for (int j=0;j+diff<len;++j)
                    for (int k = 0;k<diff;++k)
                    {
                        f[i][j][diff] |= f[i][j][k] & f[i+k+1][j+k+1][diff-k-1];
                        f[i][j][diff] |= f[i][j+diff-k][k] & f[i+k+1][j][diff-k-1];
                    }
        return f[0][0][len-1];
    }
};