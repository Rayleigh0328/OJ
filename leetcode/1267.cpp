class Solution {

    int n,m;
    
    bool comm(int x, int y, const vector<vector<int>>& g){
        if (g[x][y] == 0) return false;
        for (int i=0;i<n;++i)
            if (i != x && g[i][y] == 1) return true;
        for (int j=0;j<m;++j)
            if (j != y && g[x][j] == 1) return true;
        return false;
    }
    
public:
    int countServers(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        n = grid.size();
        m = grid[0].size();
        int ans = 0;
        for (int i=0;i<n;++i)
            for (int j=0;j<m;++j)
                if (comm(i,j,grid)) ++ans;
        return ans;
    }
};
