class Solution {
    const int obstacle_weight = 10000;
    const int inf = (1<<30);
    
    vector<int> x_diff{0,0,-1,1};
    vector<int> y_diff{-1,1,0,0};
    
    vector<vector<int>> g;
    int n,m;
    
    bool in_board(int x, int y){
        return (0 <= x && x < n && 0 <= y && y < m);
    }

    
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        g = grid;
        if (g.empty() || g[0].empty()) return -1;
        n = g.size();
        m = g[0].size();
        unordered_map<int, int> dist;
        queue<int> que;
        que.push(0);
        dist[0] = 0;
        while (!que.empty()){
            int tmp = que.front();
            int ob_cnt = tmp / obstacle_weight;
            int x = (tmp % obstacle_weight) / m;
            int y = (tmp % obstacle_weight) % m;
            que.pop();            
            for (int i=0;i<4;++i){
                int next_x = x + x_diff[i];
                int next_y = y + y_diff[i];
                if (!in_board(next_x, next_y)) continue; 
                int next_ob_cnt = ob_cnt + (g[next_x][next_y] == 1?1:0);
                if (next_ob_cnt > k) continue;
                int code = next_ob_cnt * obstacle_weight + next_x * m + next_y;
                if (dist.find(code) == dist.end() || dist[code] > dist[tmp] + 1){
                    dist[code] = dist[tmp] + 1;
                    que.push(code);
                }
            }
        }
        vector<int> feasible_code;
        for (int i=0;i<=k;++i)
            feasible_code.push_back(i*obstacle_weight + n*m-1);
        int result = inf;
        for (int code : feasible_code){
            if (dist.find(code) != dist.end())
                result = min(result, dist[code]);
        }
        if (result == inf) return -1;
        else return result;
    }
};
