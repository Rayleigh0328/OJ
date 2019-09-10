class Solution {
public:
    
    int n;
    int m;
    vector<vector<bool>> visited;
    int ans;
    int count;
    vector<int> line_diff = {-1, 0, 0, 1};
    vector<int> col_diff = {0, -1, 1, 0};
    
    bool in_board(int x, int y){
        if (x < 0) return false;
        if (x >= n) return false;
        if (y < 0) return false;
        if (y >= m) return false;
        return true;
    }
    
    void dfs(int x, int y, const vector<vector<int>>& grid){
        // cout<< x << " " << y << " " << count << endl;
        ans = max(ans, ++count);
        visited[x][y] = true;
        for (int i=0; i<4; ++i){
            int next_x = x + line_diff[i];
            int next_y = y + col_diff[i];
            if (in_board(next_x, next_y) && grid[next_x][next_y]==1 && !visited[next_x][next_y])
                dfs(next_x, next_y, grid);
        }
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;
        if (grid[0].size() == 0) return 0;
        n = grid.size();
        m = grid[0].size();
        
        for (int i=0; i<n;++i) {
            vector<bool> line;
            for (int j=0;j<m;++j) line.push_back(false);
            visited.push_back(line);
        }
        
        // cout << "visited: " << visited.size() << " " << visited[0].size() << endl;
        ans = 0;
        for (int i=0; i<n;++i)
            for (int j=0; j<m;++j)
                if (grid[i][j] == 1 && !visited[i][j]) 
                {
                    count = 0;
                    dfs(i,j, grid);
                }
        return ans;
    }
};

