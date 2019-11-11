class Solution {
    const int inf = (1<<30);
    
    vector<vector<int>> f;
    
    int solve(int left, int right){
        if (left >= right) return 0;
        if (f[left][right] != -1) return f[left][right];
        int ans = inf;
        for (int i=left; i<=right; ++i)
            ans = min(ans, i + max(solve(left, i-1),solve(i+1,right)));
        return (f[left][right] = ans);
    }
    
public:
    int getMoneyAmount(int n) {
        f = vector<vector<int>> (n+1, vector<int>(n+1, -1));
        return solve(1,n);
    }
};
