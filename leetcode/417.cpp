class Solution {
    
    const int inf = (1<<30);
    vector<int> x_diff{0,0,-1,1};
    vector<int> y_diff{1,-1,0,0};
    
    vector<vector<int>> g;
    vector<vector<bool>> p_visited;
    vector<vector<bool>> a_visited;
    int n,m;
    
    bool in_board(int x, int y){
        return (0<=x && x<n && 0<=y && y<m);
    }
    
    void fill(int x, int y, vector<vector<bool>>& visited){
        visited[x][y] = true;
        int next_x, next_y;
        for (int i=0;i<4;++i){
            next_x = x + x_diff[i];
            next_y = y + y_diff[i];
            if (in_board(next_x, next_y) && !visited[next_x][next_y] && g[next_x][next_y] >= g[x][y])
                fill(next_x, next_y, visited);
        }
    }
    
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        
        n = matrix.size();
        m = matrix[0].size();
        g = matrix;
        a_visited = p_visited = vector<vector<bool>>(n, vector<bool>(m,false));
        for (int i=0;i<n;++i)
            fill(i,0, p_visited);
        for (int j=0;j<m;++j)
            fill(0,j, p_visited);
        
        for (int i=0;i<n;++i)
            fill(i,m-1, a_visited);
        for (int j=0;j<m;++j)
            fill(n-1,j, a_visited);
        
        vector<vector<int>> ans;
        for (int i=0;i<n;++i)
            for (int j=0;j<m;++j)
                if (a_visited[i][j] && p_visited[i][j])
                    ans.push_back({i,j});
        
        return ans;
    }
};
