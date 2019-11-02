class DirectedGraph {

public:
    int n;
    vector<vector<int>> edges;

    DirectedGraph(int vertex_count):
        n(vertex_count)
    {
        edges = vector<vector<int>>(vertex_count);
    }

    void insert_edge(int from, int to){
        edges[from].push_back(to);
    }
};



class Solution {
    unordered_map<int,int> height;
    unordered_set<int> visited;
    unordered_map<int,int> diameter;
    
    void dfs(int u, const DirectedGraph &g){
        visited.emplace(u);
        
        int current_height = 0;
        vector<int> cand;
        for (int v: g.edges[u]){
            if (visited.find(v) == visited.end()){
                dfs(v,g);
                current_height = max(current_height, 1 + height[v]);
                cand.push_back(height[v]);
            }
        }
        height[u] = current_height;
        sort(cand.begin(), cand.end(), greater<int>());
        if (cand.size() == 0) diameter[u] = 0;
        else if (cand.size()==1) diameter[u] = 1 + cand[0];
        else diameter[u] = 2 + cand[0] + cand[1];
    }
    
public:
    int treeDiameter(vector<vector<int>>& edges) {
        int n = edges.size();
        DirectedGraph g(n+1);
        
        for(auto &e : edges){
            g.insert_edge(e[0],e[1]);
            g.insert_edge(e[1],e[0]);
        }    
        dfs(0,g);
        
        int ans = 0;
        for (auto &x : diameter)
            ans = max(ans, x.second);
        return ans;
    }
};
