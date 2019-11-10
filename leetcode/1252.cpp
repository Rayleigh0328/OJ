class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<vector<int>> f(n, vector<int>(m,0));
        for (auto &e : indices){
            int row = e[0];
            int col = e[1];
            for (int i=0;i<n;++i) ++f[i][col];
            for (int j=0;j<m;++j) ++f[row][j];
        }
        int ans = 0;
        for (int i=0;i<n;++i)
            for(int j=0;j<m;++j)
                if (f[i][j] & 1) ++ans;
        return ans;
    }
};
