class Solution {
private:
    int n, m;
    
    bool in_board(int x, int y)
    {
        if (x < 0 || x >=n || y < 0 || y>=m) return false;
        return true;
    }
    
    int inspect(int x, int y, vector<vector<int>>& a)
    {
        if (in_board(x,y) && a[x][y] == 1) return 1;
        return 0;
    }
    
    int count_neighbor(int x, int y, vector<vector<int>>& a)
    {
        int ans = 0;
        ans += inspect(x-1,y-1,a);
        ans += inspect(x-1, y, a);
        ans += inspect(x-1,y+1,a);
        ans += inspect(x, y-1, a);
        ans += inspect(x, y+1, a);
        ans += inspect(x+1,y-1,a);
        ans += inspect(x+1,y,  a);
        ans += inspect(x+1,y+1,a);
        return ans;
    }
    
public:
    void gameOfLife(vector<vector<int>>& board) 
    {
        vector<vector<int>> prev(board);
        n = prev.size();
        if (n == 0) return;
        m = prev[0].size();
        if (m == 0) return;
        
        for (int i=0;i<n;++i)
            for (int j=0;j<m;++j)
            {
                int cnt = count_neighbor(i,j,prev);
                if (cnt < 2 || cnt > 3) board[i][j] = 0;
                else
                    if (board[i][j] == 0 && cnt == 3)
                        board[i][j] = 1;
            }
    }
};