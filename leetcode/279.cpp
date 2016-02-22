class Solution {
private:
    const int inf = 1 << 30;
public:
    int numSquares(int n) 
    {
        int* f= new int [n+2];
        f[0] = 0;
        for (int i=1;i<n+2;++i) f[i] = inf;
            
        for (int i=1;i<=n;++i)
            for (int j=1;j*j<=i;++j)
                f[i] = min(f[i], f[i-j*j] + 1);
        int ans = f[n];
        delete [] f;
        return ans;
    }
};