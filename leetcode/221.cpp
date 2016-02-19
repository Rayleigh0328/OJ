class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        if (mat.size()==0) return 0;
        
        int h = mat.size();
        int w = mat[0].size();
        int **square, **left, **up;
        square = new int* [h];
        for (int i=0;i<h;++i) square[i] = new int [w];
        left = new int* [h];
        for (int i=0;i<h;++i) left[i] = new int [w];
        up = new int* [h];
        for (int i=0;i<h;++i) up[i] = new int [w];
        
        for (int i=0;i<h;++i)
            for (int j=0;j<w;++j)
                square[i][j] = left[i][j] = up[i][j] = 0;
        
        for (int i=0;i<h;++i)
            for (int j=0;j<w;++j)
                if (mat[i][j] == '1')
                {
                    left[i][j] = (j>0?left[i][j-1]:0) + 1;
                    up[i][j] = (i>0?up[i-1][j]:0) + 1;
                    if (i==0 || j==0) square[i][j] = 1;
                    else
                        square[i][j] = min(square[i-1][j-1], min(left[i][j-1], up[i-1][j])) + 1;
                }
        
        int ans = 0;
        for (int i=0;i<h;++i)
            for (int j=0;j<w;++j)
                ans = max(ans, square[i][j]);
        
        for (int i=0;i<h;++i) delete [] square[i];
        delete [] square;
        for (int i=0;i<h;++i) delete [] left[i];
        delete [] left;
        for (int i=0;i<h;++i) delete [] up[i];
        delete [] up;
        
        return ans * ans;
    }
};