class Solution {
    
    const int mode = 1000000007;
    
    int solve(int left, int right, vector<vector<int>> &f){
        if (left < 0 || right < 0 || right > left) return 0;
        if (f[left][right] != -1) return f[left][right];
        long long result = 0;
        result += solve(left-1, right, f);
        result += solve(left, right-1, f) * (left - right + 1ll);
        return (f[left][right] = result % mode);
    }
    
public:
    int countOrders(int n) {
        vector<vector<int>> f(n+1, vector<int>(n+1, -1));
        f[0][0] = 1;
        long long ans = solve(n,n,f);
        for (int i=2;i<=n;++i)
            ans = ans * i % mode;
        return ans;
    }
};
