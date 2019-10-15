class Solution {
    static const int max_size = 102;
    int f[max_size][max_size][max_size];
    int a[max_size];
    int n;
    
    int solve(int l, int r, int k){
        if (l > r) return 0;
        if (l == r) return (f[l][r][k] = (k+1) * (k+1));
        if (f[l][r][k] > 0) return f[l][r][k];
        
        f[l][r][k] = (k+1)*(k+1) + solve(l+1, r, 0);
        for (int p = l+1; p <=r; ++p){
            if (a[p] == a[l])
                f[l][r][k] = max(f[l][r][k], solve(l+1, p-1, 0) + solve(p, r, k+1));
        }
        return f[l][r][k];
    }
    
public:
    int removeBoxes(vector<int>& boxes) {
        n = boxes.size();
        for (int i=0;i<n;++i)
            a[i] = boxes[i];
        return solve(0,n-1,0);
    }
};
