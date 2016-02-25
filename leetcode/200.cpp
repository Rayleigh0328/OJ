class Solution {
private:
    int **flag;
    int n, m;
    
    void flood_fill(int x, int y, int label, vector<vector<char>>& g)
    {
        if (x < 0 || x>=n) return ;
        if (y < 0 || y>=m) return ;
        if (g[x][y]=='0' || flag[x][y] != 0) return ;
        
        flag[x][y] = label;
        flood_fill(x-1,y,label,g);
        flood_fill(x+1,y,label,g);
        flood_fill(x,y+1,label,g);
        flood_fill(x,y-1,label,g);
    }
public:
    int numIslands(vector<vector<char>>& g) {
        if (g.size() == 0) return 0;
        if (g[0].size() == 0) return 0;
        
        n = g.size();
        m = g[0].size();
        
        flag = new int* [n];
        for (int i=0;i<n;++i)
            flag[i] = new int [m];
        for (int i=0;i<n;++i)
            for (int j=0;j<m;++j)
                flag[i][j] = 0;
        
        int cnt = 1;
        for (int i=0;i<n;++i)
            for (int j=0;j<m;++j)
                if (g[i][j]=='1' && flag[i][j]==0)
                    flood_fill(i,j,cnt++,g);
        
        for (int i=0;i<n;++i)
            delete [] flag[i];
        delete [] flag;
        
        return cnt -1;
    }
};