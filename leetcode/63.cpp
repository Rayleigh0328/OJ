class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& ob) 
    {
        int n = ob.size();
        if (n == 0) return 1;
        int m = ob[0].size();
        if (m == 0) return 1;
        
        long long **f = new long long * [n];
        for (int i=0;i<n;++i)
            f[i] = new long long [m];
        
        f[0][0] = (ob[0][0] == 1)?0:1;
        
        for (int i=1;i<n;++i)
            f[i][0] = (ob[i][0] == 1)?0:f[i-1][0];
            
        for (int j=1;j<m;++j)
            f[0][j] = (ob[0][j] == 1)?0:f[0][j-1];
            
        for (int i=1;i<n;++i)
            for (int j=1;j<m;++j)
                if (ob[i][j] == 1) f[i][j] = 0;
                else
                    f[i][j] = f[i-1][j] + f[i][j-1];
        return f[n-1][m-1];
    }
};