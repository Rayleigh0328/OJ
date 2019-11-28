class Solution {
    static const int max_size = 105;
    int f[max_size][max_size];
    
    void count(const string &st, int &zeros, int &ones){
        zeros = ones = 0;
        for (char ch : st)
            if (ch == '0') ++zeros;
            else ++ones;
    }
    
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        for (int i=0;i<max_size;++i)
            for (int j=0;j<max_size;++j)
                f[i][j] = -1;
        f[0][0] = 0;
        int total_zero, total_one;
        for (const string &st : strs){
            count(st, total_zero, total_one);
            for (int i=n;i>=0;--i)
                for (int j=m;j>=0;--j)
                    if (f[i][j] >= 0 && i+total_one <= n && j + total_zero <= m)
                        f[i+total_one][j+total_zero] = max(f[i+total_one][j+total_zero], f[i][j] + 1);
        }
        
        int ans = 0;
        for (int i=0;i<=n;++i)
            for (int j=0;j<=m;++j)
                ans = max(ans, f[i][j]);
        return ans;
                
    }
};
