class Solution {
    int n;
    int m;
    
    bool in_board(int i, int j){
        return (0<=i && i<n && 0<=j && j<m);
    }
public:
    int largest1BorderedSquare(vector<vector<int>>& g) {
        n = g.size();
        m = g[0].size();
        vector<vector<int>> 
            up(n, vector<int>(m,0)), 
            down(n, vector<int>(m,0)), 
            left(n, vector<int>(m,0)), 
            right(n, vector<int>(m,0));
        
        for (int i=0;i<n;++i)
            for (int j=0;j<m;++j)
                if (g[i][j] == 1){
                    up[i][j] = 1 + (in_board(i-1,j)?up[i-1][j]:0);
                    left[i][j] = 1 + (in_board(i,j-1)?left[i][j-1]:0);
                }
        
        for (int i=n-1;i>=0;--i)
            for (int j=m-1;j>=0;--j)
                if (g[i][j] == 1){
                    down[i][j] = 1 + (in_board(i+1,j)?down[i+1][j]:0);
                    right[i][j] = 1 + (in_board(i,j+1)?right[i][j+1]:0);
                }
        
        int result = 0;
        for (int i=0;i<n;++i)
            for (int j=0;j<m;++j)
                if (g[i][j] == 1){
                    for (int d=0;d<=min(i,j);++d)
                        if (up[i][j] >= d+1 && down[i-d][j-d] >= d+1 && left[i][j] >= d+1 && right[i-d][j-d] >= d+1)
                            result = max(result, d+1);
                }
        
        return result * result;
    }
};
