class Solution {
    
    vector<int> x_diff={-1,-1,-1,0,0,1,1,1};
    vector<int> y_diff={-1,0,1,-1,1,-1,0,1};
    
    bool in_board(vector<vector<char>>&board, int x, int y){
        return (0<= x && x< board.size() && 0<=y && y<board[0].size());
    }
    
    int count_adj_mine(vector<vector<char>>&board, int x, int y){
        int result = 0;
        for (int d=0;d<8;++d){
            int next_x = x + x_diff[d];
            int next_y = y + y_diff[d];
            if (in_board(board, next_x, next_y) && board[next_x][next_y] == 'M') ++result;
        }
        return result;
    }
    
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int row = click[0];
        int col = click[1];
        
        // printf("row: %d, col: %d\n", row, col);
        
        if (board[row][col] == 'M'){
            board[row][col] = 'X'; 
        }
        else if (board[row][col] == 'E' && count_adj_mine(board, row, col) != 0){
            board[row][col] = count_adj_mine(board,row,col) + '0';
        }
        else {
            board[row][col] = 'B';
            for (int d=0;d<8;++d){
                int next_x = row + x_diff[d];
                int next_y = col + y_diff[d];
                if (in_board(board, next_x, next_y) && board[next_x][next_y] == 'E'){
                    vector<int> tmp = {next_x, next_y};
                    updateBoard(board, tmp);
                }
                   
            }
        }
        return board;
    }
};
