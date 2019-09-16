class Solution {

    int n, m;
    vector<vector<int>> dist;
    
    vector<int> line_diff={-1,0,0,1};
    vector<int> col_diff={0,-1,1,0};

    int encode(int x, int y){
        return x*m + y;
    }

    int decode_line(int code){
        return code/m;
    }

    int decode_col(int code){
        return code % m;
    }

    bool in_board(int x, int y){
        if (x < 0) return false;
        if (x >=n) return false;
        if (y < 0) return false;
        if (y >= m) return false;
        return true;
    }
    
    bool all_rock(vector<vector<int>>&g ){
        for (auto &vec : g)
            for (auto x : vec)
                if (x == 0) return false;
        return true;
    }

public:
    int maxDistance(vector<vector<int>>& g) { 
        if (all_rock(g)) return -1;
        n = g.size();
        if (n == 0) return 0;
        m = g[0].size();
        
        dist = vector<vector<int>>(n, vector<int>(m, -1));
        queue<int> que;
        // code (x,y) --> x*n+y
        for (int i=0;i<n;++i)
           for (int j=0;j<m;++j)
              if (g[i][j] == 1) {
                  que.push(encode(i,j));
                  dist[i][j] = 0;
#ifdef TEST
                  cout << i << " " << j <<" "<< 0 <<endl;
#endif
              }
        while (!que.empty()) {
            int code = que.front();
            que.pop();
            int x = decode_line(code);
            int y = decode_col(code);
#ifdef TEST
                  cout << "process:" << x << " " << y  <<endl;
#endif
            for (int i=0;i<4;++i){
                int next_x = x + line_diff[i];
                int next_y = y + col_diff[i];
                if (in_board(next_x, next_y) && dist[next_x][next_y] == -1){
                    dist[next_x][next_y] = dist[x][y] + 1;
                    que.push(encode(next_x, next_y));
#ifdef TEST
                  cout << next_x << " " << next_y <<" "<< dist[next_x][next_y] <<endl;
#endif
                }
            } 
        }
#ifdef TEST
    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j){
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
#endif
        int ans = -1;
        for (int i=0;i<n;++i)
            for (int j=0;j<m;++j)
                ans = max(ans, dist[i][j]);
        return ans; 
    }
};

