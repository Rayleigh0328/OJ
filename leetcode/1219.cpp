class Solution {
    int ans;
    int n,m;
    
    vector<int> x_diff = {-1, 0, 0, 1};
    vector<int> y_diff = {0, 1, -1, 0};
    
    bool in_board(int x, int y){
        if (x < 0 || x >=n) return false;
        if (y < 0 || y >=m) return false;
        return true;
    }
    
    void solve(vector<vector<int>> &g, int x, int y, int score){
        int gold = g[x][y];
        score += gold;
        g[x][y] = 0;
        ans = max(ans, score);
        
        int next_x, next_y;
        for (int i=0;i<4;++i){
            next_x = x + x_diff[i];
            next_y = y + y_diff[i];
            if (in_board(next_x, next_y) && g[next_x][next_y] > 0)
                solve(g, next_x, next_y, score);
        }
        
        g[x][y] = gold;
    }
    
public:
    int getMaximumGold(vector<vector<int>>& g) {
        n = g.size();
        if (n == 0) return 0;
        m = g[0].size();
        if (m == 0) return 0;
        
        ans = 0;
        for (int i=0; i<n; ++i)
            for (int j=0;j<m;++j)
                if (g[i][j] > 0) solve(g, i, j, 0);
        return ans;
    }
};
