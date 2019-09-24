class Solution {
    int n;
    vector<vector<bool>> visited;
    vector<int> x_diff={-1, 0, 0, 1};
    vector<int> y_diff={0, -1, 1, 0};
    
    bool in_board(int x, int y){
        if (x < 0 || x >=n ) return false;
        if (y < 0 || y >=n ) return false;
        return true;
    }

    void dfs(int x, int y, int t, const vector<vector<int>> &grid){
        if (!visited[x][y] && grid[x][y] <= t) visited[x][y] = true;
        else return;

        int next_x, next_y;
        for (int i=0;i<4;++i){
            next_x = x + x_diff[i];
            next_y = y + y_diff[i];
            if (in_board(next_x, next_y)) dfs(next_x, next_y, t, grid);
        }
    }

    bool reachable(int t, const vector<vector<int>>& grid){
        for (int i=0;i<n;++i)
            for (int j=0;j<n;++j)
                visited[i][j] = false;
        dfs(0,0, t, grid);
        if (visited[n-1][n-1]) return true;
        return false;
    }

public:
    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        visited = vector<vector<bool>> (n, vector<bool>(n));
        int left = 0;
        int right = n*n;
        int mid;
        while (left < right){
            if (left + 1 == right) return left;
            if (left + 2 == right){
                if (reachable(left, grid)) return left;
                else return left + 1;
            }

            mid = (left + right) / 2;
            if (reachable(mid, grid)) right = mid + 1;
            else left = mid + 1;
        }
        return -1;
    }
};

