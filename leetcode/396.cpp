class Solution {
public:
    int maxRotateFunction(vector<int>& a) {
        int n = a.size();
        if (n <= 1) return 0;
        
        long long sum = 0;
        for (int i=0;i<n;++i) sum += a[i];
        
        vector<long long> s(n);
        for (int i=0;i<n;++i) s[0] += i * a[i];
        
        for (int i=1;i<n;++i)
            s[i] = s[i-1] + sum - n * static_cast<long long>(a[n-i]);
        
        int ans = s[0];
        for(int i=1;i<n;++i)
            if (s[i] > ans) ans = s[i];
        return ans;
    }
};
