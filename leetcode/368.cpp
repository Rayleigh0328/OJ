class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& a) {
        
        int n = a.size();
        
        if (n == 0) return {};
        
        sort(a.begin(), a.end());
        
        vector<int> f(n,1);
        vector<int> from(n,-1);
        for (int i=0;i<n;++i)
            for (int j=0;j<i;++j)
                if (a[i] % a[j] == 0 && f[j] + 1 > f[i]){
                    f[i] = f[j] + 1;
                    from[i] = j;
                }
        
        int max_pos = 0;
        for (int i=0;i<n;++i)
            if (f[i] > f[max_pos]) max_pos = i;
        int prev = from[max_pos];
        vector<int> result{a[max_pos]};
        while (prev != -1){
            result.push_back(a[prev]);
            prev = from[prev];
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
