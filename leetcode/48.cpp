class Solution {
private:
    void solve(int xs, int ys, int step, vector<vector<int>> &matrix)
    {
        int x0,y0, x1, y1, x2, y2, x3, y3;
        for (int i=0;i<step;++i)
        {
            x0 = xs;
            y0 = ys + i;
            
            x1 = xs + i;
            y1 = ys + step; 
            
            x2 = xs + step;
            y2 = ys + step - i;
            
            x3 = xs + step - i;
            y3 = ys;
            
            int tmp = matrix[x3][y3];
            matrix[x3][y3] = matrix[x2][y2];
            matrix[x2][y2] = matrix[x1][y1];
            matrix[x1][y1] = matrix[x0][y0];
            matrix[x0][y0] = tmp;
        }
    }
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int len = matrix.size();
        for (int i=0;i<= len/2; ++i)
            solve(i,i,len-1-2*i,matrix);
    }
};