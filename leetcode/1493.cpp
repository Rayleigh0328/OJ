class Solution {
public:
    int longestSubarray(vector<int>& a) {
        const int n = a.size();
        vector<int> prev(n,0);
        vector<int> next(n,0);
        
        if (a[0] == 1) prev[0] = 1;
        for (int i=1;i<a.size();++i)
            if (a[i] == 1) prev[i] = prev[i-1] + 1;
        
        if (a[n-1] == 1) next[n-1] = 1;
        for (int i=n-2;i>=0;--i)
            if (a[i] == 1) next[i] = next[i+1] + 1;
        
        int result = 0;
        for (int i=0;i<n;++i)
            result = max(result, (i-1>=0?prev[i-1]:0) + (i+1<n?next[i+1]:0));
        return result;
    }
};
