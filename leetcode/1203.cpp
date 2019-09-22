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

class TopologicalSorter{
   vector<int> result; 
public: 
    vector<int> topological_sort(DirectedGraph g){
        vector<int> in_degree(g.n, 0);
        for (int from = 0; from < g.n; ++from){
            for (int to : g.edges[from]) ++in_degree[to];
        }
#ifdef TEST
        cout << "in degree: " << endl;
        for (auto x : in_degree) cout << x << " ";
        cout << endl;
#endif
        queue<int> que;
        for (int i=0; i<g.n;++i)
            if (in_degree[i] == 0) que.push(i);
        result = vector<int>(0);
        while (!que.empty()){
            int u = que.front();
            result.push_back(u);
            for (int v : g.edges[u]) 
                if (--in_degree[v]==0) que.push(v);
            que.pop();
        }
        return result;
    }

    bool is_acyclic(DirectedGraph g){
        return result.size() == g.n;
    }
};

class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
#ifdef TEST
        printf("beforeItems:\n");
        for (int i=0;i<n;++i){
            printf("%d: ", i);
            for (auto x : beforeItems[i]) cout << x << " ";
            cout << endl;
        }
        cout << "grpup before: ";
        for(int i=0; i<n;++i) cout << group[i] << " "; cout  << endl;
#endif
        // replace -1 with unique groups
        int tot_group = m;
        for(int i=0; i<n;++i)
            if (group[i] == -1) group[i] = tot_group++;
#ifdef TEST
        cout << "grpup after: ";
        for(int i=0; i<n;++i) cout << group[i] << " "; cout << endl;
#endif

        vector<map<int, int>> group_node_map_out_to_in(tot_group);
        vector<map<int, int>> group_node_map_in_to_out(tot_group);
        for (int i=0; i<n;++i){
            int group_count = group_node_map_out_to_in[group[i]].size();
            group_node_map_out_to_in[group[i]].emplace(i, group_count);
            group_node_map_in_to_out[group[i]].emplace(group_count, i);
        }
#ifdef TEST
        cout << "grpup map: ";
        for(int i=0; i<tot_group;++i) {
            printf("group %d:\n", i);
            for (auto x : group_node_map_out_to_in[i])
                printf("%d --> %d\n", x.first, x.second);
        }
#endif
        
        // construct graph of group
        DirectedGraph group_graph(tot_group);
        for (int v = 0; v<n; ++v){
            for (int u : beforeItems[v]) 
                if (group[u] != group[v]) {
#ifdef TEST
                    printf("for edge <%d, %d> insert group edge <%d, %d>\n", u, v, group[u], group[v]);
#endif
                    group_graph.insert_edge(group[u],group[v]);
                }
        }
#ifdef TEST
        group_graph.print();
#endif
        TopologicalSorter topo;
        vector<int> group_result = topo.topological_sort(group_graph);
        if (!topo.is_acyclic(group_graph)) return vector<int>(0);
#ifdef TEST
        cout << "topo group: ";
        for (auto x : group_result) cout << x << " "; cout << endl;
#endif
        
        // topological sort within group
        vector<vector<int>> group_topo(tot_group);
        for (int i=0; i<tot_group;++i){
            map<int,int>& group_map = group_node_map_out_to_in[i];
            DirectedGraph group_g(group_map.size());
            for (auto it = group_map.begin(); it != group_map.end(); ++it){
                int v = it->first;
                for (int u : beforeItems[v])
                    if (group_map.find(u) != group_map.end()) 
                        group_g.insert_edge(group_map[u],group_map[v]);
            }
#ifdef TEST
            printf("group graph for group %d\n", i);
            group_g.print();
#endif
            TopologicalSorter ts;
            group_topo[i] = ts.topological_sort(group_g);
#ifdef TEST
        cout << "topo inside group "<< i <<": ";
        //for (auto x : group_topo[i]) cout << group_node_map_in_to_out[i][x] << " "; cout << endl;
        for (auto x : group_topo[i]) cout << x << " "; cout << endl;
#endif
            if (!ts.is_acyclic(group_g)) return vector<int>(0);
        }
        
        vector<int>result; 
        for (int group : group_result){
            for (int tmp : group_topo[group])
                result.push_back(group_node_map_in_to_out[group][tmp]);
        }
        return result;
    }
};

