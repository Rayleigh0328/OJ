class Solution {
public:
    int minFlipsMonoIncr(string s) {
        // f[i] make s[0..i] monotone, s[i] == 0
        // g[i] make s[0..i] monotone, s[i] == 1
        
        int inf = (1<<29);
        if (s.empty()) return 0;
        int f=0, g=0;
        if (s[0] == '0') ++g;
        else ++f;
        
        int fn, gn;
        for (int i=1;i<s.size();++i){
            fn = f + (s[i]=='0'?0:1);
            gn = (s[i]=='1'?0:1) + min(g,f);
            f = fn;
            g = gn;
        }
        return min(f,g);
    }
};
