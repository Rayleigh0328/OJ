class Solution {
    const int inf = (1<<28);
public:
    int minSumOfLengths(vector<int>& a, int target) {
        const int n = a.size();
        
        vector<int> f(n, inf);
        unordered_map<int, int> mp;
        mp[0] = -1;
        int sum = 0;
        for (int i=0;i<n;++i){
            sum += a[i];
            if (mp.find(sum - target) != mp.end()) f[i] = i - mp[sum-target];
            mp[sum] = i;
        }
        for (auto x : f) printf("%d ", x); printf("\n");
        
        int result = inf;
        vector<int> dp(n, inf);
        dp[0] = f[0];
        for (int i=1;i<n;++i){
            dp[i] = min(dp[i-1], f[i]);
            if (f[i] != inf && i-f[i] >= 0)
            result = min(result, f[i] + dp[i-f[i]]);
        }
        if (result >= inf) return -1;
        return result;
    }
};
