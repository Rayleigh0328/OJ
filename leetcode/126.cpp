struct Graph{
    int tot_v;
    int tot_e;
    vector<unordered_set<int>> edge;
    
    Graph(int size){
        tot_v = size;
        edge = vector<unordered_set<int>>(tot_v);
    }
    
    void insert_edge(int u, int v){
        edge[u].emplace(v);
    }
};

class Solution {
    
    int inf = (1<<30);
    
    int solve(Graph &g, int start, int end){
        vector<int> dist(g.tot_v, inf);
        vector<bool> in_que(g.tot_v);
        queue<int> que;
        
        que.push(start);
        in_que[start] = true;
        dist[start] = 0;
        
        int u,v;
        while (!que.empty()){
            u = que.front();
            for (auto v : g.edge[u])
                if (dist[v] > dist[u] + 1){
                    dist[v] = dist[u] + 1;
                    if (!in_que[v]){
                        in_que[v] = true;
                        que.push(v);
                    }
                }
            que.pop();
            in_que[u] = false;
        }
        return dist[end];
    }
    
    bool connect(const string &s1, const string &s2){
        int count_diff = 0;
        for (int i=0;i<s1.length();++i)
            if (s1[i] != s2[i]) ++count_diff;
        return (count_diff == 1);
    }
    
    void dfs(
        Graph &g,
        int node, 
        int current_depth, 
        int target_node, 
        int target_depth,
        vector<int>& dist,
        vector<int>& state, 
        vector<vector<int>>& result
    ){
        // printf("%d, depth: %d, target:%d\n", node, current_depth);
        // for (auto x : state) cout << x << " "; cout << endl;
        if (current_depth > target_depth) return ;
        if (current_depth > dist[node]) return;
        else dist[node] = current_depth;
        
        if (node == target_node){
            result.push_back(state);
            return;
        }
        
        for (auto v : g.edge[node]){
            state.push_back(v);
            dfs(g,v,current_depth+1,target_node,target_depth,dist, state,result);
            state.pop_back();
        }
    }
    
    void convert(vector<vector<int>>& index_result, vector<vector<string>>& string_result, string& special, vector<string> word_list){
        
        for (auto &v : index_result){
            vector<string> row{special};
            for (auto ind : v) row.push_back(word_list[ind]);
            string_result.push_back(row);
        }
    }
    
public:
    vector<vector<string>> findLadders(string begin_word, string end_word, vector<string>& word_list) {
        vector<vector<string>> result;
        
        // construct graph
        int n = word_list.size();
        Graph g(n+1);
        // begin_word corresponding to vertex n
        // insert edges related to n
        for (int i=0;i<n;++i)
            if (connect(begin_word, word_list[i])){
                g.insert_edge(i, n);
                g.insert_edge(n, i);
            }
        
        // find the vertex corresponding to end_word
        int end_index=-1;
        for (int i=0;i<n;++i)
            if (word_list[i] == end_word){
                end_index = i;
                break;
            }
        if (end_index == -1) return result;
        
        // insert other edges
        for (int i=0;i<n;++i)
            for (int j=0;j<n;++j)
                if (connect(word_list[i], word_list[j])){
                    g.insert_edge(i,j);
                    g.insert_edge(j,i);
                }
        
        // for (int i=0;i<g.edge.size();++i)
        //     for (int j : g.edge[i])
        //         printf("%d,%d\n",i,j);
        
        int ans = solve(g, n, end_index);
        if (ans >= inf) return result;
        cout << ans << endl;
        
        vector<int> state;
        vector<vector<int>> tmp;
        vector<int> dist(n+1,inf);
        
        dfs(g, n, 0, end_index, ans, dist, state, tmp);
        convert(tmp,result, begin_word, word_list);
        return result;
    }
};
