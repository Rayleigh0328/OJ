class Solution {
public:
    int mincostTickets(vector<int>& a, vector<int>& costs) {
        int n = a.size();
        vector<int> f(n);
        
        for (int i=0;i<n;++i){
            f[i] = (i==0?0:f[i-1]) + costs[0];
            for (int j=i;j>=0;--j){
                if (a[i]-a[j] > 30) break;
                if (a[i]-a[j]<7) f[i] = min(f[i], (j==0?0:f[j-1]) + costs[1]);
                if (a[i]-a[j]<30) f[i] = min(f[i], (j==0?0:f[j-1]) + costs[2]);
            }
        }

        return f[n-1];
    }
};
