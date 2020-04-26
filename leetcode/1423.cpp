class Solution {
public:
    int maxScore(vector<int>& cd, int k) {
        const int n = cd.size();
        
        vector<int> a;
        for (auto x : cd) a.push_back(x);
        for (auto x : cd) a.push_back(x);
        vector<int> f(2*n);
        f[0] = a[0];
        for (int i=1;i<a.size();++i)
            f[i] = f[i-1] + a[i];
        
        if (k == n) return f[n-1];
        
        int result = 0;
        for (int i=n - k; i<=n;++i)
            result = max(result, f[i+k-1] - f[i-1]);
        return result;
    }
};
