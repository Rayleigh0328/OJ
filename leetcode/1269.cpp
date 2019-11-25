class Solution {
    
    const int mode = 1000000007;
    
    int n;
    int limit;
    
    void solve(const vector<long long>& f, vector<long long>&g){
        for (int i=0;i<=n;++i) g[i] = 0;
        for (int i=0;i<=n;++i)
            g[i] = ((i-1>=0?f[i-1]:0) + f[i] + (i+1<=min(n,limit)?f[i+1]:0)) % mode;
    }
    
public:
    int numWays(int steps, int arrLen) {
        n = steps;
        limit = arrLen-1;
        vector<long long> f(n+1, 0);
        vector<long long> g(n+1, 0);
        f[0] = 1;
        for (int i=1;i<=n;++i)
            if (i&1) solve(f,g);
            else solve(g,f);
        if (n&1) return g[0];
        else return f[0];
    }
};
