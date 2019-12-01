class Solution {
    static const int max_size = 105;
    static const int inf = (1<<20);
    
    int f[max_size][max_size];
    string s;
    int n;
    
    int solve(int left, int right){
        string tmp = s.substr(left, right-left);
        int ans = 0;
        for (int i=0;i<(tmp.size()+1)/2;++i)
            if (tmp[i] != tmp[tmp.size()-1-i]) ++ans;
        return ans;
    }
    
public:
    int palindromePartition(string str, int k) {
        s = str;
        n = s.size();
        for (int i=0;i<max_size;++i)
            for (int j=0;j<max_size;++j)
                f[i][j] = inf;
        f[0][0] = 0;
        for (int i=1;i<=n;++i)
            for (int j=1;j<=i;++j){
                for (int k=0;k<i;++k)
                    f[i][j] = min(f[i][j], f[k][j-1] + solve(k,i));
            }
        return f[n][k];
    }
};
