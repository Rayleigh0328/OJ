class Solution {
    
    const int inf = (1<<28);
    
public:
    int minDistance(vector<int>& a, int target) {
        
        const int n = a.size();
        sort(a.begin(), a.end());
        vector<vector<int>> cost(n, vector<int>(n, inf));
        for (int i=0;i<n;++i)
            for (int j=i;j<n;++j){
                cost[i][j] = 0;
                for (int k=i;k<=j;++k)
                    cost[i][j] += abs(a[k]-a[(i+j)/2]);
            }
        
        vector<int> f(n, inf);
        for (int t=1;t<=target;++t){
            for (int i=n-1;i>=0;--i)
                for (int j=0;j<=i;++j)
                    f[i] = min(f[i], (j-1>=0?f[j-1]:0) + cost[j][i]);
        }
        return f[n-1];
    }
};
