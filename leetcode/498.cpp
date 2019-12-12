class Solution {
    
    int n,m;
    
    bool in_board(int x, int y){
        return (0<=x && x<n && 0<=y && y<m);
    }
    
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty() || matrix[0].empty()) return {};
        n = matrix.size();
        m = matrix[0].size();
        int x,y;
        for (int d = 0; d < n + m - 1; ++d)
            if (d & 1){
                // go down
                x = 0;
                y = d;
                if (!in_board(x,y)){
                    x = d - m + 1;
                    y = m-1;
                }
                while (in_board(x,y)){
                    result.push_back(matrix[x][y]);
                    x+=1;
                    y-=1;
                }
            }
            else{
                // go up
                x = d;
                y = 0;
                if (!in_board(x,y)){
                    x = n-1;
                    y = d - n + 1;
                }
                while (in_board(x,y)){
                    result.push_back(matrix[x][y]);
                    x-=1;
                    y+=1;
                } 
            }
        return result;
    }
    
};
