class Solution {
    
    int n;
    int cc_count;
    vector<int> cc;
    vector<int> cc_size;
    vector<int> cc_infected_size;
    unordered_set<int> init_set;
    
    void dfs(vector<vector<int>>& g, int k, int flag){
        if (cc[k] != -1) return;
        cc[k] = flag;
        for (int i=0;i<n;++i)
            if (g[k][i] == 1)
                dfs(g, i, flag);
    }
    
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
         
        
        // if infected nodes = 1 then the whole CC will not be infected 
        n = graph.size();
        cc_count = 0;
        cc = vector<int>(n, -1);
        for (auto x : initial)
            init_set.emplace(x);
        
        // calculate connected component
        for (int i=0;i<n;++i)
            if (cc[i] == -1)
                dfs(graph,i,cc_count++);
        
        // determine size of each CC
        vector<int> cc_size(cc_count, 0);
        for (int i=0;i<n;++i)
            ++cc_size[cc[i]];
        
        // determine # of infected nodes in each CC
        vector<int> cc_infected_size(cc_count,0);
        for (int i=0;i<n;++i)
            if (init_set.find(i) != init_set.end())
                ++cc_infected_size[cc[i]];

        int result = -1;
        int save_size = -1;
        for (int i=0;i<n;++i){
            if (init_set.find(i) != init_set.end()){
                int cur_save_size = 0;
                if (cc_infected_size[cc[i]] == 1){
                    cur_save_size = cc_size[cc[i]];
                }
                if (cur_save_size > save_size){
                    save_size= cur_save_size;
                    result = i;
                }
            }
        }
        return result;
    }
};
