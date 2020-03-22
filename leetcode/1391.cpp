class Solution {
    
    vector<vector<int>> diff_x{{0,0} , {-1,1}, {0,1}, {0,1}, {-1,0}, {-1,0}};
    vector<vector<int>> diff_y{{-1,1}, {0,0}, {-1,0}, {1,0}, {0,-1}, {0,1} };
    
    int n,m;
    bool in_board(int x, int y){
        return (0<=x && x<n && 0<=y && y<m);
    }
    
    bool can_connect(int x, int y, int d){
        if (x == 1){
            if (y == 2) return false;
            if (d == 0 && (y == 3 || y == 5)) return false;
            if (d == 1 && (y == 4 || y == 6)) return false;
        }
        if (x == 2){
            if (y == 1) return false;
            if (d == 0 && (y == 5 || y == 6)) return false;
             if (d == 1 && (y == 3 || y == 4)) return false;
        }
        if (x == 3){
            if (d == 0 && (y == 2 || y == 3 || y == 5)) return false;
            if (d == 1 && (y == 1 || y == 4)) return false;
        }
        if (x == 4){
            if (d == 0 && (y == 2 || y==4 || y == 6)) return false;
            if (d == 1 && (y == 1 || y == 3)) return false;
        }
        if (x == 5){
            if (d == 0 && (y == 1 || y == 5 || y == 6)) return false;
            if (d == 1 && (y == 2 || y == 3 || y == 5)) return false;
        }
        if (x == 6){
            if (d == 0 && (y == 1 || y == 5 || y == 6)) return false;
            if (d == 1 && (y == 2 || y == 4 || y == 6)) return false;
        }
        return true;
    }
    
    void dfs(int x, int y, vector<vector<bool>> &visited, const vector<vector<int>>& g){
        // printf("dfs %d %d\n", x,y);
        if (!in_board(x,y)) return;
        if (visited[x][y]) return;
        visited[x][y] = true;
        for (int i=0;i<2;++i){
            int dx = diff_x[g[x][y]-1][i];
            int dy = diff_y[g[x][y]-1][i];
            if (in_board(x+dx, y+dy) && can_connect(g[x][y], g[x+dx][y+dy], i))
                dfs(x + dx, y + dy, visited, g);
        }
    }
    
public:
    bool hasValidPath(vector<vector<int>>& g) {
        n = g.size();
        m = g[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        dfs(0,0,visited, g);
        return visited[n-1][m-1];
    }
};
