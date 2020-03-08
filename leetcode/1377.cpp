class Solution {
    int n;
    vector<vector<int>> e;
    vector<int>p;
        
    void dfs(int k, vector<int>&p){
        for (auto u : e[k]){
            if (p[u] == -2){
                p[u] = k;
                dfs(u, p);
            }
        }
    }
    
    void solve(vector<double> &f, vector<double> &g){
        // for (auto x : f) printf("%f ", x); printf("\n");
        for (int i=0;i<n;++i) g[i] = 0;
        for (int i=1;i<n;++i){
            // printf("process node %d, child count: %d\n", i, e[i].size());
            if (e[i].size() == 1) g[i] = f[i];
            int parent = p[i];
            int child_count = (parent == 0?0:-1) + e[parent].size();
            g[i] += f[parent] / child_count;
        }
    }
    
public:
    double frogPosition(int nn, vector<vector<int>>& input_edges, int t, int target) {
        // treat 1 as root
        n = nn;
        if (n == 1) return 1.0;
        
        e = vector<vector<int>>(n);
        for (auto &edge : input_edges){
            int u = edge[0]-1;
            int v = edge[1]-1;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        p = vector<int>(n, -2);
        p[0] = -1;
        dfs(0, p);
        
        vector<double> f(n, 0);
        vector<double> g(n, 0);
        f[0] = 1;
        // printf("t:%d\n", t);
        for (int i=1;i<=t;++i)
            if (i & 1) solve(f,g);
            else solve(g,f);
        if (t & 1) return g[target-1];
        else return f[target-1];
    }
};
