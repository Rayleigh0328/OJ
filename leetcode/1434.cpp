class Solution {
    
    const int mode = 1000000007;
    const int max_hat = 41;
    
    int max_state;
    
public:
    int numberWays(vector<vector<int>>& hats) {
        int n = hats.size();
        max_state = (1<<n);
        
        vector<unordered_set<int>> a(max_hat);
        for (int i=0;i<hats.size();++i)
            for (int j=0;j<hats[i].size();++j)
                a[hats[i][j]].emplace(i);
        
        vector<vector<int>> f(max_hat, vector<int>(max_state,0));
        f[0][0] = 1;
        
        for (int i=1;i<=40;++i){
            for (int p : a[i])
                for (int s=max_state-1;s>=0;--s)
                    if ((s & (1<<p)) == 0)
                        f[i][s + (1<<p)] = (f[i][s + (1<<p)] + f[i-1][s]) % mode;
            
            for (int s=max_state-1;s>=0;--s) 
                f[i][s] = (f[i][s] + f[i-1][s]) % mode;
        }
        
        return f[max_hat-1][max_state-1];
    }
};
