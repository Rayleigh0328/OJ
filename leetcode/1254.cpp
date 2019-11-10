class Solution {
    
    vector<int> x_diff{0,0,-1,1};
    vector<int> y_diff{1,-1,0,0};

    vector<vector<bool>> visited;
    vector<vector<int>> g;
    int n,m;
    
    bool in_board(int x, int y){
        if (x < 0 || x >= n) return false;
        if (y < 0 || y >= m) return false;
        return true;
    }
    
    void flood_fill(int x, int y){
        
        visited[x][y] = true;
        
        int next_x, next_y;
        for (int i=0;i<4;++i){
            next_x = x + x_diff[i];
            next_y = y + y_diff[i];
            if (in_board(next_x,next_y) && !visited[next_x][next_y] && g[x][y] == 0)
                flood_fill(next_x, next_y);
        }
    }
    
public:
    int closedIsland(vector<vector<int>>& grid) {
        g = grid;
        n = grid.size();
        if (n == 0) return 0;
        m = grid[0].size();
        if (m == 0) return 0;
        
        visited=vector<vector<bool>>(n, vector<bool>(m, false));
        
        // flood fill 0s on the boundry
        for (int i=0;i<n;++i){ 
            if (g[i][0] == 0 && !visited[i][0]) flood_fill(i,0);
            if (g[i][m-1] == 0 && !visited[i][m-1]) flood_fill(i,m-1);
        }
        
        for (int j=0;j<m;++j){
            if (g[0][j] == 0 && !visited[0][j]) flood_fill(0,j);
            if (g[n-1][j] == 0 && !visited[n-1][j]) flood_fill(n-1,j);
        }
        
        // flood fill 0s not on the boundry
        int ans = 0;
        for (int i=1;i<n-1;++i)
            for (int j=0;j<m-1;++j)
                if (g[i][j] == 0 && !visited[i][j]){
                    ++ans;
                    flood_fill(i,j);
                }
        
        return ans;
    }
};
