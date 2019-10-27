struct Graph{
    int tot_v;
    int tot_e;
    vector<vector<int>> edge;
    
    Graph(int size){
        tot_v = size;
        edge = vector<vector<int>>(tot_v);
    }
    
    void insert_edge(int u, int v){
        edge[u].push_back(v);
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
    
public:
    int ladderLength(string begin_word, string end_word, vector<string>& word_list) {
        int n = word_list.size();
        Graph g(n+1);
        for (int i=0;i<n;++i)
            if (connect(begin_word, word_list[i])){
                g.insert_edge(i, n);
                g.insert_edge(n, i);
            }
        int end_index=-1;
        for (int i=0;i<n;++i)
            if (word_list[i] == end_word){
                end_index = i;
                break;
            }
        if (end_index == -1) return 0;
        
        for (int i=0;i<n;++i)
            for (int j=0;j<n;++j)
                if (connect(word_list[i], word_list[j])){
                    g.insert_edge(i,j);
                    g.insert_edge(j,i);
                }
        
        int ans = solve(g, n, end_index) + 1;
        if (ans >= inf) return 0;
        return ans;
    }
};
