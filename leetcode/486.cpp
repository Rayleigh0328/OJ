class Solution {
    static const int max_size = 30;
    int f[max_size][max_size];
    int sum[max_size][max_size];
    int n;
public:
    bool PredictTheWinner(vector<int>& a) {
        n = a.size();
        for (int i=0;i<n;++i){
            sum[i][i] = a[i];
            for (int j=i+1;j<n;++j)
                sum[i][j] = sum[i][j-1] + a[j];
        }
        for (int i=0;i<n;++i) f[i][i] = a[i];
        for (int len = 1; len < n; ++len){
            for (int i=0;i<n;++i){
                if (i + len >= n) break;
                int j = i+len;
                f[i][j] = max(sum[i][j]-f[i][j-1], sum[i][j]-f[i+1][j]);
            }
        }
        
        // printf("f: %d, sum: %d\n", f[0][n-1], sum[0][n-1]);
        return (f[0][n-1]*2 >= sum[0][n-1]);
    }
};
