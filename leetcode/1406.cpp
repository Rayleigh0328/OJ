class Solution {
    const int inf = (1<<29);
public:
    string stoneGameIII(vector<int>& a) {
        const int n = a.size();
        
        vector<int> sum(n,0);
        sum[n-1] = a[n-1];
        for (int i=n-2;i>=0;--i)
            sum[i] = a[i] + sum[i+1];
        
        vector<int> f(n, -inf);
        f[n-1] = a[n-1];
        
        for(int i=n-2;i>=0;--i){
            f[i] = max(f[i], a[i] + (i+1<n?sum[i+1] - f[i+1]:0));
            if (i+1 < n) f[i] = max(f[i], a[i] + a[i+1] + (i+2<n?sum[i+2] - f[i+2]:0));
            if (i+2 < n) f[i] = max(f[i], a[i] + a[i+1] + a[i+2] + (i+3<n?sum[i+3] - f[i+3]:0));
        }
                       
        if (f[0] * 2 > sum[0]) return "Alice";
        else if (f[0] * 2 < sum[0]) return "Bob";
        return "Tie";
    }
};
