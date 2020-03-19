class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int, int> count;
        for (auto x : nums) ++count[x];
        vector<pair<int, int>> a;
        for (auto &x : count) a.push_back(x);
        const int n = a.size();
        if (n == 0) return 0;
        vector<int> f(n,0);
        vector<int> g(n,0);
        f[0] = a[0].first * a[0].second;        
        for (int i=1;i<n;++i){
            f[i] = a[i].first * a[i].second;
            if (a[i-1].first + 1 == a[i].first) f[i] += g[i-1];
            else f[i] += max(f[i-1], g[i-1]);
            g[i] = max(g[i-1], f[i-1]);
        }
        return max(f[n-1], g[n-1]);
    }
};
