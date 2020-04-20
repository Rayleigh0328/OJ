class Solution {
    const int inf = (1<<29);
public:
    int maxValueAfterReverse(vector<int>& a) {
        const int n = a.size();
        
        int original = 0;
        for (int i=1;i<n;++i) original += abs(a[i]-a[i-1]);
        
        vector<int> b,c;
        for (int i=0;i<n-1;++i) b.push_back(max(a[i], a[i+1]));
        for (int i=0;i<n-1;++i) c.push_back(min(a[i], a[i+1]));
        int min_b = inf, max_c = -inf;
        for (auto x : b) min_b = min(min_b, x);
        for (auto x : c) max_c = max(max_c, x);
        int ans = original;
        if (max_c - min_b > 0) ans += (max_c-min_b) * 2;
        
        // special case: reverse prefix
        for (int i=0;i<n-1;++i)
            ans = max(ans, original - abs(a[i+1]-a[i]) + abs(a[i+1]-a[0]));
        // special case: reverse suffix
        for (int i=n-1;i>0;--i)
            ans = max(ans, original - abs(a[i-1]-a[i]) + abs(a[i-1]-a[n-1]));
        
        return ans;
    }
};
