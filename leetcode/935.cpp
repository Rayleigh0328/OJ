class Solution {
    
    const int mode = 1000000007;
    
    vector<vector<int>> next = {
        {4,6},
        {6,8},
        {7,9},
        {4,8},
        {3,9,0},
        {},
        {1,7,0},
        {2,6},
        {1,3},
        {2,4}
    };
    
    
    void solve(vector<int> &f, vector<int> &g){
        for (int i=0;i<10;++i) g[i] = 0;
        for (int i=0;i<10;++i)
            for (auto x : next[i])
                g[x] = (g[x] + f[i]) % mode;
    }
    
public:
    int knightDialer(int n) {
        vector<int> f(10,1);
        vector<int> g(10,0);
        for (int i=1;i<n;++i)
            if (i & 1) solve(f,g);
            else solve(g,f);
        int result = 0;
        for (int i=0;i<10;++i)
            if (n & 1) result = (result + f[i]) % mode;
            else result = (result + g[i]) % mode;
        return result;
    }
};
