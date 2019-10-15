class Solution {
    
public:
    int movesToMakeZigzag(vector<int>& a) {
        // process to a[i] and end the sequence with j
        // f[i][j] odd position greater than even position
        // g[i][j] odd position smaller than even position 
        
        const int inf = (1<<25);
        int n = a.size();
        int max_value = 1002;
        
        int f[n][max_value];
        int g[n][max_value];
        for (int i=0;i<n;++i)
            for (int j=0;j<max_value;++j)
                f[i][j] = g[i][j] = inf;
        
//         for (int i=0;i<n;++i){
//             for (int j=0;j<5;++j) printf("%d ",f[i][j]);
//             cout << endl;
//         }
        
        for (int j=0;j<=a[0];++j)
            f[0][j] = g[0][j] = a[0] - j;
        
        for (int i=1;i<n;++i){
            // range 0 - a[i]
            if (i & 1){
                int min_value = f[i-1][0];
                for (int j=1;j<=a[i];++j){
                    f[i][j] = min_value + a[i] - j;
                    min_value = min(min_value, f[i-1][j]);
                }
            }
            else{
                int min_value = inf;
                for(int j=a[i-1]; j>a[i]; --j) min_value = min(min_value, f[i-1][j]);
                for (int j = a[i]; j>=0;--j){
                    f[i][j] = min_value + a[i] - j;
                    min_value = min(min_value, f[i-1][j]);
                }
            }
        }
            
        for (int i=1;i<n;++i){
            // range 0 - a[i]
            if (!(i & 1)){
                int min_value = g[i-1][0];
                for (int j=1;j<=a[i];++j){
                    g[i][j] = min_value + a[i] - j;
                    min_value = min(min_value, g[i-1][j]);
                }
            }
            else{
                int min_value = inf;
                for(int j=a[i-1]; j>a[i]; --j) min_value = min(min_value, g[i-1][j]);
                for (int j = a[i]; j>=0;--j){
                    g[i][j] = min_value + a[i] - j;
                    min_value = min(min_value, g[i-1][j]);
                }
            }
        }
        
        int ans = inf;
        for (int j=0;j<max_value;++j) ans = min(ans, f[n-1][j]);
        for (int j=0;j<max_value;++j) ans = min(ans, g[n-1][j]);
        return ans;
    }
};
