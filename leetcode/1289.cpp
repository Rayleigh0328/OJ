class Solution {
    const int inf = (1<<28);
public:
    int minFallingPathSum(vector<vector<int>>& a) {
        if (a.empty() || a[0].empty()) return 0;
        int n = a.size();
        int m = a[0].size();
        vector<vector<int>> f(n, vector<int>(m,inf));
        for (int j=0;j<m;++j) f[0][j] = a[0][j];
        for (int i=1;i<n;++i){
            vector<int> v;
            for (int j=0;j<m;++j) v.push_back(j);
            sort(v.begin(), v.end(), [&f, &i](const int &x,const int &y){return f[i-1][x] < f[i-1][y];});


            for (int j=0;j<m;++j){
                if (j==v[0]) f[i][j] = f[i-1][v[1]] + a[i][j];
                else f[i][j] = f[i-1][v[0]] + a[i][j];
            }
        }

        int result = inf;
        for (int j=0;j<m;++j)
            result = min(result, f[n-1][j]);
        return result;
    }
};
