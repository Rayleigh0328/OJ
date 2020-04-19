class Solution {
    
    const int max_length = 55;
    const int upper_bound = 105;
    const int mode = 1000000007;
    
public:
    int numOfArrays(int n, int m, int cost) {
        long long f[max_length][max_length][upper_bound];
        memset(f, 0, sizeof(f));
        
        for (int k=1;k<=m;++k) f[0][1][k] = 1;
        
        for (int i=1;i<n;++i)
            for (int j=1;j<=cost;++j)
                for (int k=1;k<=m;++k){
                    f[i][j][k] = (f[i][j][k] + f[i-1][j][k] * k) % mode;
                    for (int p=1;p<k;++p)
                        f[i][j][k] = (f[i][j][k] + f[i-1][j-1][p]) % mode;
                }
                     
        int result = 0;
        for (int k=0;k<=m;++k)
            result = (result + f[n-1][cost][k]) % mode;
        return result;
    }
};
