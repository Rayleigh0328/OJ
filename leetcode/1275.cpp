class Solution {
    
public:
    string tictactoe(vector<vector<int>>& moves) {
        int grid[3][3];
        for (int i=0;i<3;++i)
            for (int j=0;j<3;++j)
                grid[i][j] = 0;
        
        int count=0;
        for (const auto &move : moves){
            int x = move[0];
            int y = move[1];
            if (count++ % 2 == 0) grid[x][y]=1;
            else grid[x][y] = -1;
        }
        
        int win = 0;
        // check row
        for (int i=0;i<3;++i)
            if (grid[i][0] != 0 && grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2])
                win = grid[i][0];
        // check col 
        for (int j=0;j<3;++j)
            if (grid[0][j] != 0 && grid[0][j] == grid[1][j] && grid[1][j] == grid[2][j])
                win = grid[0][j];
        // check diagnol
        if (grid[0][0] != 0 && grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2])
            win = grid[0][0];
        if (grid[0][2] != 0 && grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0])
            win = grid[0][2];
        
        if (win == 1) return "A";
        else if (win == -1) return "B";
        else if (moves.size() == 9) return "Draw";
        else return "Pending";
    }
};
