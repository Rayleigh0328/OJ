class Solution {
    const int inf = (1<<28);
    static const int max_size = 80;
    
    int f[max_size][max_size][max_size];
    
    int n,m;
    
    int get(int f[max_size][max_size][max_size], int i, int j, int k){
        if (i < 0 || i >=n || j<0 || j>=m || k<0 || k>=m ) return -inf;
        return f[i][j][k];
    }
    
public:
    int cherryPickup(vector<vector<int>>& g) {
        n = g.size();
        m = g[0].size();
        
        // init
        for (int i=0;i<max_size;++i)
            for (int j=0;j<max_size;++j)
                for (int k=0;k<max_size;++k)
                    f[i][j][k] = -inf;
        
        // boundary
        f[0][0][m-1] = g[0][0] + g[0][m-1];
        
        for (int i=1;i<n;++i)
            for (int j=0;j<m;++j)
                for (int k=0;k<m;++k){
                    f[i][j][k] = max(f[i][j][k], get(f,i-1,j-1,k-1));
                    f[i][j][k] = max(f[i][j][k], get(f,i-1,j-1,k));
                    f[i][j][k] = max(f[i][j][k], get(f,i-1,j-1,k+1));               
                    
                    f[i][j][k] = max(f[i][j][k], get(f,i-1,j,k-1));
                    f[i][j][k] = max(f[i][j][k], get(f,i-1,j,k));
                    f[i][j][k] = max(f[i][j][k], get(f,i-1,j,k+1)); 
                    
                    f[i][j][k] = max(f[i][j][k], get(f,i-1,j+1,k-1));
                    f[i][j][k] = max(f[i][j][k], get(f,i-1,j+1,k));
                    f[i][j][k] = max(f[i][j][k], get(f,i-1,j+1,k+1)); 
                    
                    if (j == k) f[i][j][k] += g[i][j];
                    else f[i][j][k] += g[i][j] + g[i][k];
                }

        int result = -inf;
        for(int j=0;j<m;++j)
            for (int k=0;k<m;++k)
                result = max(result, f[n-1][j][k]);
        return result;
    }
};
