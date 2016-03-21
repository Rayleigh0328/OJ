class Solution {
private:
    void get_next(int &x, int &y, int &d, int n, int m, bool** flag)
    {
        int x_next=x, y_next=y;
        switch (d)
        {
        case 0:
            ++y_next;
            break;
        case 1:
            ++x_next;
            break;
        case 2:
            --y_next;
            break;
        case 3:
            --x_next;
            break;
        }
        
        if (x_next< 0 || x_next>=n || y_next < 0 || y_next >= m || flag[x_next][y_next])
        {
            d = (d+1) % 4;
            get_next(x,y,d,n,m,flag);
        }
        else
        {
            x = x_next;
            y = y_next;
        }
        
    }
    
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return vector<int>();
        
        vector<int> ans;
        ans.clear();
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        bool** flag = new bool* [n];
        for (int i=0;i<n;++i)
            flag[i] = new bool [m];
        for (int i=0;i<n;++i)
            for (int j=0;j<m;++j)
                flag[i][j] = false;
        
        int x = 0, y = 0, d = 0;
        for (int i=0;i<n*m-1;++i)
        {
            ans.push_back(matrix[x][y]);
            flag[x][y] = true;
            get_next(x,y,d,n,m,flag);
        }
        ans.push_back(matrix[x][y]);
        return ans;
    }
};