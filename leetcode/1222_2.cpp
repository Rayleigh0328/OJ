class Solution {

    void add_ans(int x, int y, vector<vector<int>> &v){
        v.push_back(vector<int>{x,y});
    }
    
    bool inboard(int x, int y){
        if (x < 0 || x >=8) return false;
        if (y < 0 || y >=8) return false;
        return true;
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
        
        vector<int> diff_x{-1, 1, 0,  0, 1,  1, -1, -1};
        vector<int> diff_y{0,  0, 1, -1, 1, -1,  1, -1};
        
        vector<vector<int>> ans;
        for (int i=0; i<8;++i)
            for (x=kx,y=ky; inboard(x,y); x+=diff_x[i], y+=diff_y[i])
                if (g[x][y]) {
                    add_ans(x,y,ans);
                    break;
                }

        return ans;
    }
};

