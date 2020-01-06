class Solution {
    
    
    vector<int> x_diff{0,1,1};
    vector<int> y_diff{1,0,1};
    const int mode = 1000000007;
    const int inf = (1<<28);
    
    int n,m;
    vector<vector<int>> f,g;
    
    
    bool in_board(int x, int y){
        return (0 <= x && x < n && 0<=y && y < m);
    }
    
    int get_value(char ch){
        if (ch == 'X') return -inf;
        if ('0' <= ch && ch <= '9') return ch - '0';
        return 0;
    }
    
    
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        n = board.size();
        m = board[0].size();
        f = vector<vector<int>>(n, vector<int>(m, -inf));
        g = vector<vector<int>>(n, vector<int>(m, -1));
        f[n-1][m-1] = 0;
        g[n-1][m-1] = 1;
        for (int i=n-1;i>=0;--i)
            for (int j=m-1;j>=0;--j)
                if (board[i][j] != 'X'){
                    for (int k=0; k<3;++k){
                        int next_x = i + x_diff[k];
                        int next_y = j + y_diff[k];
                        if (in_board(next_x, next_y)){
                            if (f[i][j] < get_value(board[next_x][next_y]) + f[next_x][next_y]){
                                f[i][j] = get_value(board[next_x][next_y]) + f[next_x][next_y];
                                g[i][j] = g[next_x][next_y];
                            }
                            else if (f[i][j] == get_value(board[next_x][next_y]) + f[next_x][next_y]){
                                g[i][j] = (g[i][j] + g[next_x][next_y]) % mode;
                            }
                        }
                    }
                }
        if (f[0][0] < 0) return {0,0};
        return {f[0][0], g[0][0]};
    }
};
