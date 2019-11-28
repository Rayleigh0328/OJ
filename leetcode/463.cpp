class Solution {

    vector<int> x_diff{0,0,1,-1};
    vector<int> y_diff{1,-1,0,0};
    
    bool in_board(int x, int y, int x_limit, int y_limit){
        return (0 <= x && x < x_limit && 0 <= y && y < y_limit);
    }
    
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        int next_row, next_col;
        for (int i=0;i<n;++i)
            for (int j=0;j<m ;++j)
                if (grid[i][j] == 1)
                    for (int d=0;d<4;++d){
                        next_row = i + x_diff[d];
                        next_col = j + y_diff[d];
                        if (!in_board(next_row, next_col, n, m) || grid[next_row][next_col] == 0) ++ans;
                    }
        return ans;
    }
};
