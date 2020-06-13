class Solution {
    
    static const int max_size = 102;
    static const int inf = (1<<28);
    
    int f[max_size][max_size][max_size];
    
public:
    // m house, n colors
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        
        
        for (int i=0;i<max_size;++i)
            for (int j=0;j<max_size;++j)
                for (int k=0;k<max_size;++k)
                    f[i][j][k] = inf;
        
        // init
        if (houses[0] != 0){
            f[0][1][houses[0]-1] = 0;
        }
        else {
            for (int c = 0; c<n; ++c)
                f[0][1][c] = cost[0][c];
        }
        
        // dp
        for (int i=1;i<m;++i){
            if (houses[i] != 0){
                int cur = houses[i] - 1;
                for (int j=1;j<=i+1;++j)
                    for (int prev=0;prev<n;++prev)
                        if (cur == prev){
                            f[i][j][cur] = min(f[i][j][cur], f[i-1][j][prev]);
                        }
                        else {
                            f[i][j][cur] = min(f[i][j][cur], f[i-1][j-1][prev]);
                        }
                        
            }
            else {
                for (int j=1;j<=i+1;++j)
                    for (int cur=0;cur<n;++cur)
                        for (int prev=0;prev<n;++prev)
                            if (cur == prev){
                                f[i][j][cur] = min(f[i][j][cur], f[i-1][j][prev] + cost[i][cur]);
                            } 
                            else {
                                f[i][j][cur] = min(f[i][j][cur], f[i-1][j-1][prev] + cost[i][cur]);
                            }
            }
        }
        // printf("%d\n", f[0][1][0]);
        // printf("%d\n", f[0][1][1]);
        // printf("%d\n", f[1][1][0]);
        // printf("%d\n", f[1][1][1]);
        // printf("%d\n", f[1][2][0]);
        // printf("%d\n", f[1][2][1]);
        
        // result
        int result = inf;
        for (int c=0;c<n;++c)
            result = min(result, f[m-1][target][c]);
        if (result >= inf) return -1;
        return result;
            
    }
};
