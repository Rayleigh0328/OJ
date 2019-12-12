class Solution {
    
    void solve(unordered_map<int, int> &from, unordered_map<int, int> &to, int k){
        to.clear();
        for (auto e : from){
            to[e.first + k] += e.second;
            to[e.first - k] += e.second;
        }
    }
    
public:
    int findTargetSumWays(vector<int>& a, int target) {
        unordered_map<int, int> f{{0,1}};
        unordered_map<int, int> g;
        for (int i=0;i<a.size();++i)
            if (i & 1) 
                solve(g, f, a[i]);
            else
                solve(f, g, a[i]);
        
        if (a.size() & 1)
            return g[target];
        else
            return f[target];
    }
};
