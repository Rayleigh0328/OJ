class Solution {
private:
    int n;
    int m;
    int k=9;
    vector<int> line_diff{-1,-1,-1, 0, 0, 0, 1, 1, 1};
    vector<int>  col_diff{-1, 0, 1,-1, 0, 1,-1, 0, 1};
    
    bool in_board(int x, int y){
        if (x < 0) return false;
        if (x >= n) return false;
        if (y < 0) return false;
        if (y >= m) return false;
        return true;
    }
    
    int solve(vector<vector<int>>& original, int x, int y){
        int count = 0;
        int sum = 0;
        for (int i=0; i<9; ++i)
            if (in_board(x+line_diff[i], y+col_diff[i])){
                ++count;
                sum += original[x+line_diff[i]][y+col_diff[i]];
            }
        // printf("(%d, %d), %d, %d\n", x, y, count, sum);
        return sum/count;
    }
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& original) {
        
        n = original.size();
        m = original[0].size();
        // printf("board %d x %d\n", n, m);
        vector<vector<int>> result;
        for (int i=0; i<n;++i){
            vector<int> line;
            result.push_back(line);
            for (int j=0;j<m;++j)
                result[i].push_back(solve(original, i,j));
        }
    
        return result;
    }
};
