class Solution {

    int n, m;
    vector<vector<int>> g, f;
    
    int get(int x, int y){
        if (x < 0 || y < 0 || g[x][y] == 0) return 0;
        return f[x][y];
    }
    
public:
    int countSquares(vector<vector<int>>& matrix) {
        g = matrix;
        if (g.empty() || g[0].empty()) return 0;
        n = g.size();
        m = g[0].size();
        f= vector(n, vector<int>(m, 0));
        
        for (int i=0;i<n;++i)
            for (int j=0;j<m;++j)
                if (g[i][j] == 1){
                    f[i][j] = 1 + min(min(get(i-1, j-1), get(i-1,j)), get(i,j-1));
                }
        
        int ans=0;
        for (int i=0;i<n;++i)
            for (int j=0;j<m;++j)
                ans += f[i][j];
        
        return ans;
    }
};
