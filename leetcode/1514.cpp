class DirectedGraph {
public:
    
    double inf = (1<<30);
    
    int n;
    vector<unordered_map<int,double>> edges;

    DirectedGraph(int vertex_count):
        n(vertex_count)
    {
        edges = vector<unordered_map<int, double>>(vertex_count);
    }

    void insert_edge(int from, int to, double w){
        edges[from][to] = w;
    }
    
    vector<double> spfa(int start){
        int u,v;
        double w;
        vector<double> dist(n,inf);
        dist[start] = 0;
        
        queue<int> que;
        que.push(start);
        while (!que.empty()){
            u = que.front();
            que.pop();
            // printf("process %d\n", u);
            // for (auto x : dist) printf("%lf ", x); printf("\n");
            for (auto e : edges[u]){
                v = e.first;
                w = e.second;
                if (dist[v] > dist[u] + w){
                    dist[v] = dist[u] + w;
                    que.push(v);
                }
            }
        }
        return dist;
    }
    
};

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        DirectedGraph g(n);
        const int m = edges.size();
        for (int i=0;i<m;++i){
            g.insert_edge(edges[i][0], edges[i][1], -log(succProb[i]));
            g.insert_edge(edges[i][1], edges[i][0], -log(succProb[i]));
        }
        vector<double> dist = g.spfa(start);
        if (dist[end] >= g.inf) return 0;
        return 1/exp(dist[end]);
    }
};
