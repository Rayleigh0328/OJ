class Solution {
    const int inf = (1<<29);
public:
    int constrainedSubsetSum(vector<int>& a, int k) {
        const int n = a.size();
        multiset<int> ms;
        vector<int> f(n,-inf);
        f[0] = a[0];
        ms.emplace(f[0]);
        int cand;
        for (int i=1;i<n;++i){
            cand = *ms.rbegin();
            if (cand < 0) cand = 0;
            f[i] = cand + a[i];
            ms.emplace(f[i]);
            if (i-k>=0){
                ms.erase(ms.find(f[i-k]));
            }
        }
        
        int result = -inf;
        for (auto x : f)
            result = max(result, x);
        return result;
    }
};
