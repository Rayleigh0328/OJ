class Solution {
    const int inf = (1<<28);
    int n,m;
    
    int get(vector<vector<int>>&vec, int row, int col){
        if (col < 0) return inf;
        if (col >=m ) return inf;
        return vec[row][col];
    }
    
public:
    int minFallingPathSum(vector<vector<int>>& a) {
        n = a.size();
        m = a[0].size();
        
        vector<vector<int>> f(n, vector<int>(m,inf));
        for (int j=0;j<m;++j) f[0][j] = a[0][j];
        
        for (int i=1;i<n;++i)
            for (int j=0;j<m;++j){
                f[i][j] = min(f[i][j], get(f,i-1,j-1));
                f[i][j] = min(f[i][j], get(f,i-1,j));
                f[i][j] = min(f[i][j], get(f,i-1,j+1));
                f[i][j] += a[i][j];
            }

        int result = inf;
        for (int j=0;j<m;++j)
            result = min(result, f[n-1][j]);
        return result;
    }
};
