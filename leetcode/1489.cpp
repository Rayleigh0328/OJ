class DisjointSet{
    vector<int> a;
public:    
    DisjointSet(){
    }
    
    DisjointSet(int n){
        a = vector<int>(n);
        for (int i=0;i<n;++i) a[i] = i;
    }
    
    void union_set(int x, int y){
        a[find_set(x)] = find_set(y);
    }
    
    int find_set(int x){
        if (a[x] == x) return x;
        else return (a[x] = find_set(a[x]));
    }
};


class Solution {
    
    const int inf = (1<<28);
    
    int kruskal(int n, vector<vector<int>>&edges, int skip_index, int choose_position){
        
        DisjointSet ds(n);
        int index,u,v,w;
        int result = 0, count = 0;
        if (choose_position != -1){
            u = edges[choose_position][1];
            v = edges[choose_position][2];
            w = edges[choose_position][3];
            ds.union_set(u,v);
            ++count;
            result += w;
        }
        for (auto &edge : edges){
            index = edge[0];
            u = edge[1];
            v = edge[2];
            w = edge[3];
            
            if (index == skip_index || ds.find_set(u) == ds.find_set(v)) continue;
            ds.union_set(u,v);
            result += w;
            if (++count == n-1) break;
        }
        if (count == n-1) return result;
        return inf;
    }
    
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<vector<int>> E;
        for (int i=0;i<edges.size();++i) E.push_back({i, edges[i][0], edges[i][1], edges[i][2]});
        sort(E.begin(), E.end(), [](const vector<int> &x, const vector<int> &y){
            return x[3] < y[3];
        });
        
        vector<int> critical, pseudo;
        int optimal = kruskal(n, E, -1, -1);
        // printf("optimal MST: %d\n", optimal);
        int cur;
        for (int i=0;i<E.size();++i){
            // printf("\nprocess edge %d\n", E[i][0]);
            cur = kruskal(n,E,E[i][0],-1);
            // printf("ST1: %d\n", cur);
            if (cur > optimal){
                critical.push_back(E[i][0]);
                continue;
            }
            
            cur = kruskal(n, E, -1, i);
            // printf("ST2: %d\n", cur);
            
            if (cur == optimal)
                pseudo.push_back(E[i][0]);
        }
        return {critical, pseudo};
    }
};
