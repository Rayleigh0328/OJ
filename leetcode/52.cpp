class Solution {
private:
    unsigned int mask;
    int ans;
    int size;
    
    void solve(int row, unsigned int col, unsigned int ld, unsigned int rd)
    {
        unsigned int available = (~(col | ld | rd) ) & mask;
        int pos;
        while (available > 0)
        {
            pos = -available & available;
            available -= pos;
            
            if (row == size-1) ++ans;
            else solve(row+1, col|pos, ((ld|pos)>>1) & mask, ((rd|pos)<<1) & mask);
        }
    }
public:
    int totalNQueens(int n) {
        size = n;
        mask = (1 << n) - 1;
        ans = 0;
        solve(0,0,0,0);
        return ans;
    }
};