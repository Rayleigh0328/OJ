class Solution {
private:
    void update(int &x, int &y, int &d, int** g)
    {
        int tmp_x=x, tmp_y=y;
        if (d == 0) ++tmp_y;
        if (d == 1) ++tmp_x;
        if (d == 2) --tmp_y;
        if (d == 3) --tmp_x;
        
        if (g[tmp_x][tmp_y] != 0)
        {
            d = (d+1)%4;
            update(x,y,d,g);
        }
        else
        {
            x = tmp_x;
            y = tmp_y;
        }
    }
public:
    vector<vector<int>> generateMatrix(int n) 
    {
        if (n <= 0) return vector<vector<int>>();
        
        int size = n + 2;
        int **g = new int* [size];
        for (int i=0;i<size;++i)
            g[i] = new int [size];
        for (int i=0;i<size;++i)
            for (int j=0;j<size;++j)
                g[i][j] = -1;
        for (int i=1;i<size-1;++i)
            for (int j=1;j<size-1;++j)
                g[i][j] = 0;
        
        int x = 1, y = 1, d = 0;
        for (int i=1;i<n*n;++i)
        {
            g[x][y] = i;
            update(x,y,d,g);
            //cout << x << " " << y << endl;
        }
        g[x][y] = n*n;
        
        vector<vector<int>> ans;
        ans.clear();
        for (int i=1;i<=n;++i)
        {
            ans.push_back(vector<int>());
            for (int j=1;j<=n;++j)
                ans[ans.size()-1].push_back(g[i][j]);
        }
        return ans;
    }
};