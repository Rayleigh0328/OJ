class Solution {
private:
    unsigned int mask;
    vector<vector<string>> ans;
    int size;
    
    string get_string(int pos)
    {
        string ans = "";
        for (int i=0;i<size;++i)
        {
            ans += (((pos&1)==1)?'Q':'.');
            pos = pos >> 1;
        }
        return ans;
    }
    
    void solve(int row, unsigned int col, unsigned int ld, unsigned int rd, vector<string>& state)
    {
        unsigned int available = (~(col | ld | rd) ) & mask;
        int pos;
        while (available > 0)
        {
            pos = -available & available;
            available -= pos;
            state.push_back(get_string(pos));
            if (row == size-1)
                ans.push_back(state);
            else solve(row+1, col|pos, ((ld|pos)>>1) & mask, ((rd|pos)<<1) & mask, state);
            state.pop_back();
        }
    }
    
public:
    vector<vector<string>> solveNQueens(int n) 
    {
        size = n;
        mask = (1 << n) - 1;
        ans.clear();
        vector<string> tmp;
        tmp.clear();
        solve(0,0,0,0,tmp);
        return ans;
    }
};
