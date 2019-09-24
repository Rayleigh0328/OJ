class DirectedGraph {

public:
    int n;
    vector<vector<int>> edges;

    DirectedGraph(){
        n = 0;
    }
    
    DirectedGraph(int vertex_count):
        n(vertex_count)
    {
        edges = vector<vector<int>>(vertex_count);
    }

    void insert_edge(int from, int to){
        edges[from].push_back(to);
    }

    void print(){
        printf("-------------------------\n");
        printf("print graph with %d nodes, labeled from 0 to %d \n", n, n-1);
        printf("edges:\n");
        for (int u=0;u<n;++u)
            for (int v : edges[u]){
                printf("<%d,%d>\n", u, v);
            }
        printf("-------------------------\n");
    }
};



class Solution {

    DirectedGraph g;
    vector<int> color;
    bool stop_dfs=false;
    bool is_unique;
    int x, y;
    
    void dfs(int current){
        if (stop_dfs) return;
        color[current] = 1; 
        for (auto next : g.edges[current]){
            if (color[next] == 0) {
                dfs(next);
            }
            else if (color[next] == 1){
                x = current;
                y = next;
                is_unique = true;
                stop_dfs = true;
                return ;
            }
            else {
                x = current;
                y = next;
                is_unique = false;
                stop_dfs = true;
                return ;
            }
        }
        if (!stop_dfs) color[current] = 2;
    }

public:
    Solution(){
        
    }
    
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> in_degree(n+1,0);
        g = DirectedGraph(n+1);
        for (auto edge : edges){ 
            g.insert_edge(edge[0], edge[1]); 
            ++in_degree[edge[1]];
        }
        int root=-1;
        for (int i=1;i<n+1;++i) {
            if (in_degree[i] == 0) {
                root = i;
                break;
            }
        }
        
        color = vector<int>(n+1, 0);
        if (root == -1){
            printf("no root found\n");
            for (int i=1;i<=n;++i) {
                if (color[i] == 0) dfs(i);
                if (stop_dfs) break; 
            }
            for (auto it = edges.rbegin(); it != edges.rend(); ++it){
                if ( color[(*it)[1]] == 1 && color[(*it)[0]] == 1) return (*it);
            }
        }
        else{
            dfs(root);
            if (is_unique) return vector<int>{x,y};
            else {
                for (auto it = edges.rbegin(); it != edges.rend(); ++it){
                    if ( (*it)[1] == y) return (*it);
                }
            }
        }
        return vector<int>(0);
    }
};
