class Solution {

    void add_ans(int x, int y, vector<vector<int>> &v){
        v.push_back(vector<int>{x,y});
    }

public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        // 0: nothing
        // 1: queen
        const int n = 8;
        vector<vector<int>> g(n, vector<int>(n, 0));
        int x, y;
        for (auto &e : queens){
            g[e[0]][e[1]] = 1;
        }

        int kx = king[0];
        int ky = king[1];
        vector<vector<int>> ans;
        // left
        for (y = ky - 1; y>=0; --y)
            if (g[kx][y] == 1){
                add_ans(kx,y, ans);
                break;
            }
        // right
        for (y = ky + 1; y<n; ++y)
            if (g[kx][y] == 1){
                add_ans(kx,y,ans);
                break;
            }
        // up
        for (x = kx - 1; x >=0; --x)
            if (g[x][ky] == 1){
                add_ans(x,ky,ans);
                break;
            }
        // down
        for (x = kx + 1; x < n; ++x)
            if (g[x][ky] == 1){
                add_ans(x,ky,ans);
                break;
            }
        // up left
        for (x = kx-1, y=ky-1; x>=0 && y>=0; --x,--y)
            if (g[x][y] == 1){
                add_ans(x,y,ans);
                break;
            }
        // up right
        for (x = kx-1, y=ky+1; x>=0 && y<n; --x,++y)
            if (g[x][y] == 1){
                add_ans(x,y,ans);
                break;
            }
        // down left
        for (x = kx+1, y=ky-1; x<n && y>=0; ++x,--y)
            if (g[x][y] == 1){
                add_ans(x,y,ans);
                break;
            }
        // down right
        for (x = kx+1, y=ky+1; x<n && y<n; ++x,++y)
            if (g[x][y] == 1){
                add_ans(x,y,ans);
                break;
            }

        return ans;
    }
};

