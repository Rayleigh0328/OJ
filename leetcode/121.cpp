class Solution {
public:
    int maxProfit(vector<int>& p) 
    {
        if (p.empty()) return 0;
        int n = p.size();
        vector<int> a;
        a.push_back(p[0]);
        for (int i=1;i<n;++i)
            a.push_back(min(a[i-1],p[i]));
        int ans = 0;
        for (int i=0;i<n;++i)
            ans = max(ans, p[i]-a[i]);
        return ans;
    }
};