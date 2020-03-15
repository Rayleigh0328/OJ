class Solution {
    
    const int inf = (1<<28);
    
public:
    vector<int> luckyNumbers (vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        vector<int> row_min(n, inf);
        vector<int> col_max(m, -inf);
        for (int i=0;i<n;++i)
            for (int j=0;j<m;++j){
                if (a[i][j] < row_min[i]) row_min[i] = a[i][j];
                if (a[i][j] > col_max[j]) col_max[j] = a[i][j];
            }
        vector<int> result;
        for (int i=0;i<n;++i)
            for (int j=0;j<m;++j){
                if (a[i][j] == row_min[i] && a[i][j] == col_max[j])
                    result.push_back(a[i][j]);
            }
        return result;
    }
};
