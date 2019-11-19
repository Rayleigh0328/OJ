class Solution {
public:
    int countBattleships(vector<vector<char>>& g) {
        if (g.empty() || g[0].empty()) return 0;
        int n = g.size();
        int m = g[0].size();
        int ans = 0;
        for (int i=0;i<n;++i)
            for (int j=0;j<m;++j)
                if (g[i][j] == 'X'){
                    ++ans;
                    g[i][j] = 'M';
                    if (j+1 < m && g[i][j+1] == 'X'){
                        for (int k=j+1;k<m && g[i][k] == 'X';++k)
                            g[i][k] = 'M';
                    }
                    else if (i+1 < n && g[i+1][j] == 'X'){
                        for (int k=i+1;k<n && g[k][j] == 'X';++k)
                            g[k][j] = 'M';
                    }
                }
        return ans;
    }
};
