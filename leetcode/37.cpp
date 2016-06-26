class Solution 
{
private:
    struct pos
    {
        int r,c;
        pos(int x, int y)
        {
            r = x;
            c = y;
        }
    };
    
    vector<pos> var;
    set<int> row_set[9];
    set<int> col_set[9];
    set<int> sqr_set[9];
    
    int n;
    int *a;
    
    int get_sqr_index(int x, int y)
    {
        int sqr_x = x / 3;
        int sqr_y = y / 3;
        return 3*sqr_x + sqr_y;
    }
    
    void solve()
    {
        int k = 0;
        while (k < n)
        {
            if (a[k] >= 9)
            {
                a[k] = 0;
                if (k == 0) cout << "ERROR" << endl;
                row_set[var[k-1].r].erase(a[k-1]);
                col_set[var[k-1].c].erase(a[k-1]);
                sqr_set[get_sqr_index(var[k-1].r, var[k-1].c)].erase(a[k-1]);
                --k;
                continue;
            }
            
            int x = var[k].r;
            int y = var[k].c;    
            
            ++a[k];
            
            if (row_set[x].find(a[k]) != row_set[x].end() ||
                col_set[y].find(a[k]) != col_set[y].end() ||
                sqr_set[get_sqr_index(x,y)].find(a[k]) != sqr_set[get_sqr_index(x,y)].end())
            {   
                continue;
            }
            else
            {
                row_set[x].insert(a[k]);
                col_set[y].insert(a[k]);
                sqr_set[get_sqr_index(x,y)].insert(a[k]);
                ++k;
            }
        }

    }
    
public:
    void solveSudoku(vector<vector<char>>& board) 
    {
        var.clear();
        for (int i=0;i<9;++i)
        {
            row_set[i].clear();
            col_set[i].clear();
            sqr_set[i].clear();
        }
        
        // scan board, put all position of '.' into vector var
        for (int i=0;i<9;++i)
            for (int j=0;j<9;++j)
            {
                if (board[i][j] == '.')
                {
                    var.push_back(pos(i,j));
                }
                else
                {
                    int digit = board[i][j]-'0';
                    // cout << i << " " << j << " " << digit << endl;
                    row_set[i].insert(digit);
                    col_set[j].insert(digit);
                    sqr_set[get_sqr_index(i,j)].insert(digit);
                }
            }
        
        n = var.size();
        cout << "var size: " << n << endl;
        a = new int [n];
        for (int i=0;i<n;++i) a[i] = 0;
        
        // non-recursively solve the puzzle, array a denote the state
        // recursive method mey lead to stack overflow
        solve();
        
        // fill the result back into board
        for (int i=0;i<n;++i)
        {
            board[var[i].r][var[i].c] = '0' + a[i];
        }
        
        delete [] a;
    }
};