class Solution {
public:
    int maxSatisfaction(vector<int>& a) {
        const int n = a.size();
        
        sort(a.begin(), a.end());
        if (a.back() <= 0) return 0;
        
        vector<int> sum(n,0);
        sum[n-1] = a[n-1];
        for (int i=n-2;i>=0;--i)
            sum[i] = sum[i+1] + a[i];
        
        int current = 0;
        for (int i=0;i<n;++i)
            current += a[i] * (i+1);
        
        int result = max(0, current);
        for (int i=1;i<n;++i){
            current -= sum[i-1];
            result = max(result, current);
        }
        
        return result;
    }
};
