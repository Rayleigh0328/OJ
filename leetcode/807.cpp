class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& g) {
        int n = g.size();
        int m = g[0].size();
        vector<int> row_max(n,0);
        vector<int> column_max(m,0);
        for (int i=0;i<n;++i)
            for (int j=0;j<m;++j){
                row_max[i] = max(row_max[i], g[i][j]);
                column_max[j] = max(column_max[j], g[i][j]);
            }
        
        int ans = 0;
        for (int i=0;i<n;++i)
            for (int j=0;j<m;++j)
                ans += min(row_max[i], column_max[j]) - g[i][j];
        
        return ans;
    }
};
