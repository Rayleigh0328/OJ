class Solution {
    
    const int inf = (1<<28);
    
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& edge, vector<vector<int>>& q) {
        vector<vector<int>> g(n, vector<int>(n,inf));
        for (int i=0;i<n;++i) g[i][i] = 0;
        for (auto &e : edge)
            g[e[0]][e[1]] = 1;
        for (int k = 0;k<n;++k)
            for (int i=0;i<n;++i)
                for (int j=0;j<n;++j)
                    if (i != k && j != k && k != j)
                        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
        
        vector<bool> result;
        for (auto &query : q){
            result.push_back(g[query[0]][query[1]] < inf);
        }
        return result;
    }
};
