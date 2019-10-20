class Solution {

    static const int max_size = 1005;
    static const int inf = (1<<28);
    
    int f[max_size][max_size];
    int from[max_size][max_size];
    int n,m;
    string a,b;
    
    
public:
    string shortestCommonSupersequence(string str1, string str2) {
        a = str1;
        n = a.length();
        b=str2;
        m = b.length();
        
        for (int i=0;i<max_size;++i)
            for (int j=0;j<max_size;++j){
                f[i][j]=inf;
                from[i][j] = -1;
            }
        
        for (int j=0;j<=m;++j) f[0][j] = j;
        for (int i=0;i<=n;++i) f[i][0] = i;
        
        for (int i=1;i<=n;++i)
            for (int j=1;j<=m;++j){
                if (a[i-1] == b[j-1] && f[i-1][j-1] + 1 < f[i][j]){
                    f[i][j] = f[i-1][j-1] + 1;
                    from[i][j] = 0;
                }
                if (f[i-1][j] + 1 < f[i][j]){
                    f[i][j] = f[i-1][j] + 1;
                    from[i][j] = 1;
                }
                if (f[i][j-1] + 1 < f[i][j]){
                    f[i][j] = f[i][j-1] + 1;
                    from[i][j] = 2;
                }
            }
        // printf("%d\n", f[n][m]);
        string ans = "";
        int i, j;
        for (i=n,j=m; i>0 && j>0;){
            if (from[i][j] == 0) {
                ans = a[i-1] + ans;
                --i;--j;
            }
            else if (from[i][j] == 1){
                ans = a[i-1] + ans;
                --i;
            }
            else {
                ans = b[j-1] + ans;
                --j;
            }
        }
        while (i > 0) ans = a[--i] + ans;
        while (j > 0) ans = b[--j] + ans;
        return ans;
    }
};
