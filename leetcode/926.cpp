class Solution {
public:
    int minFlipsMonoIncr(string s) {
        // f[i] make s[0..i] monotone, s[i] == 0
        // g[i] make s[0..i] monotone, s[i] == 1
        
        int inf = (1<<29);
        if (s.empty()) return 0;
        int n = s.size();
        vector<int> f(n,inf), g(n,inf);
        g[0] = f[0] = 0;
        if (s[0] == '0') ++g[0];
        else ++f[0];
        
        for (int i=1;i<n;++i){
            f[i] = f[i-1] + (s[i]=='0'?0:1);
            g[i] = (s[i]=='1'?0:1) + min(g[i-1],f[i-1]);
        }
        return min(f[n-1],g[n-1]);
    }
};
