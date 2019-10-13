class Solution {
    int max_rep = 17;
    int mode = 1000000007;
    vector<vector<vector<int>>> f;
    
    void solve(int i, int j, int k, vector<vector<vector<int>>>& f, vector<int>& roll_max){
        if (k == 0 || k > roll_max[j]) return;
        if (k > 1){
            f[i][j][k] = f[i-1][j][k-1];
            return;
        }
        long long ans = 0ll;
        for (int p = 0; p<6; ++p)
            if (p != j)
                for (int q = 0; q<max_rep; ++q)
                    ans += f[i-1][p][q];
        ans %= mode;
        f[i][j][k] = ans;
    }
    
public:
    int dieSimulator(int n, vector<int>& roll_max) {
        f = vector<vector<vector<int>>>(n+1, vector<vector<int>>(6, vector<int>(max_rep,0)));
        // boundary
        for (int j=0;j<6;++j) f[1][j][1]=1;
        // dp
        for (int i=2;i<=n;++i)
            for (int j=0;j<6;++j)
                for (int k=0;k<max_rep;++k){
                    solve(i,j,k,f,roll_max);
                }
       // get ans
       long long result = 0ll;
       for (int j=0; j<6;++j)
          for (int k=0; k<max_rep;++k)
              result += f[n][j][k];
       return (int) (result % mode);
    }
};

