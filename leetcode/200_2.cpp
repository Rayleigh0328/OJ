int x_diff[] = {1,-1,0,0};
int y_diff[] = {0,0,-1,1};

class Solution {
    int n,m;
    
    bool inboard(int x, int y){
        if (x < 0 || x >=n) return false;
        if (y < 0 || y >=m) return false;
        return true;
    }
    
    void flood_fill(int x, int y, const vector<vector<char>>& grid, vector<vector<bool>>& visited){
        // printf("fill %d %d\n", x,y);
        queue<int> que_x;
        queue<int> que_y;
        visited[x][y] = true;
        que_x.push(x);
        que_y.push(y);
        
        while (!que_x.empty()){
            int cur_x = que_x.front();
            int cur_y = que_y.front();
            que_x.pop();
            que_y.pop();
            
            for (int i=0;i<4;++i){
                int next_x = cur_x + x_diff[i];
                int next_y = cur_y + y_diff[i];
                if (inboard(next_x, next_y) && grid[next_x][next_y] =='1' && !visited[next_x][next_y]){
                    visited[next_x][next_y] = true;
                    que_x.push(next_x);
                    que_y.push(next_y);
                }
            }
        }
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        if (n == 0) return 0;
        m = grid[0].size();
        if (m == 0) return 0;
        vector<vector<bool>> visited(n, vector<bool>(m,false));
        int ans = 0;
        for (int i=0;i<n;++i)
            for (int j=0;j<m;++j)
                if (grid[i][j] == '1' && !visited[i][j]){
                    ++ans;
                    flood_fill(i,j,grid,visited);
                }
        return ans;
    }
};
