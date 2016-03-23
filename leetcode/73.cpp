class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        if (n == 0) return;
        int m = matrix[0].size();
        if (m == 0) return;
        
        bool zero_line = false;
        for (int i=0;i<m;++i) 
            if (matrix[0][i] == 0)
            {
                zero_line = true;
                break;
            }
        bool zero_col = false;
        for (int i=0;i<n;++i)
            if (matrix[i][0]==0)
            {
                zero_col = true;
                break;
            }
        //cout << zero_line << " " << zero_col << endl;
        for (int i=1;i<n;++i)
            for (int j=1;j<m;++j)
                if (matrix[i][j] == 0)
                    matrix[0][j] = matrix[i][0] = 0;
        
        for (int i=1;i<n;++i)
            if (matrix[i][0] == 0)
                for (int j=1;j<m;++j)
                    matrix[i][j] = 0;
        
        for (int j=1;j<m;++j)
            if (matrix[0][j] == 0)
                for (int i=1;i<n;++i)
                    matrix[i][j] = 0;
        
        if (zero_line)
            for (int j=0;j<m;++j) matrix[0][j] = 0;
        if (zero_col)
            for (int i=0;i<n;++i) matrix[i][0] = 0;
    }
};