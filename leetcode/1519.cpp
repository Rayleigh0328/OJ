class Solution {
    
    vector<vector<int>> count;
    vector<vector<int>> edges;
    vector<bool> visited;
    string labels;
    
    void dfs(int u){
        visited[u] = true;
        count[u][labels[u]-'a'] = 1;
        for (auto &v : edges[u])
            if (!visited[v]){
                dfs(v);
                for (char ch = 'a'; ch <='z'; ++ch)
                    count[u][ch-'a'] += count[v][ch-'a'];
            }
    }
    
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& input_edges, string input_labels) {
        
        
        edges = vector<vector<int>>(n);
        for (auto &e : input_edges){
            edges[e[0]].push_back(e[1]);
            edges[e[1]].push_back(e[0]);
        }
        
        labels = input_labels;
        count = vector<vector<int>>(n, vector<int>(26,0));
        visited = vector<bool>(n,false);
        dfs(0);
        
        vector<int> ans(n);
        for (int i=0;i<n;++i)
            ans[i] = count[i][labels[i]-'a'];
        return ans;
    }
};
