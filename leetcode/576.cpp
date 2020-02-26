
class Solution {
    const int mode = 1000000007;
    vector<int> diff_row={0,0,-1,1};
    vector<int> diff_col={-1,1,0,0};
public:
    int findPaths(int n, int m, int N, int i, int j) {
        vector<vector<int>> a(n,vector<int>(m,0));
        vector<vector<int>> b(n,vector<int>(m,0));
        a[i][j] = 1;
        long long result = 0;
        for (int i=0;i<N;++i)
            if (i & 1) solve(result, b, a);
            else solve(result, a, b);
        return result;
    }

private:
    void solve(long long &result, vector<vector<int>> &a, vector<vector<int>> &b){
        for (int i=0;i<a.size();++i)
            for (int j=0;j<a[0].size();++j)
                b[i][j] = 0;

        for (int i=0;i<a.size();++i)
            for (int j=0;j<a[0].size();++j)
                for (int d = 0; d < 4; ++d){
                    int next_row = i + diff_row[d];
                    int next_col = j + diff_col[d];
                    if (in_board(a.size(), a[0].size(), next_row, next_col)){
                        b[next_row][next_col] += a[i][j];
                        b[next_row][next_col] %= mode;
                    }
                    else {
                        result += a[i][j];
                        result %= mode;
                    }
                }
    }

    bool in_board(int max_row, int max_col, int row, int col){
        return (0<=row && row <max_row && 0<=col & col<max_col);
    }
};
