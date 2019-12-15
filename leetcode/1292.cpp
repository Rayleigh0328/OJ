class Solution {
    const int inf = (1<<28);
    vector<vector<int>> a;
    int n,m;
    int threshold;
    
    bool check(int len){
        vector<vector<int>> f(n, vector<int>(m, inf));
        for (int row=0;row + len<=n;++row){
            f[row][0] = 0;
            for (int i=0;i<len;++i)
                for (int j=0;j<len;++j)
                    f[row][0] += a[row+i][j];
            if (f[row][0] <= threshold) return true;
            for (int col = 1; col + len <=m; ++col){
                f[row][col] = f[row][col-1];
                for (int i=0;i<len;++i)
                    f[row][col] -= a[row+i][col-1];
                for (int i=0;i<len;++i)
                    f[row][col] += a[row+i][col+len-1];
                if (f[row][col] <= threshold) return true;
            }
        }
        return false;
    }
    
public:
    int maxSideLength(vector<vector<int>>& mat, int thr) {
        a = mat;
        threshold = thr;
        if (a.empty() || a[0].empty()) return 0;
        n = a.size();
        m = a[0].size();
        int left = 1, right = min(n,m) + 1, mid;
        while (left < right){
            if (left + 1 == right) 
                if (check(left)) return left;
                else return 0;
            if (left + 2 == right){
                if (check(left+1)) return left+1;
                else if (check(left)) return left;
                return 0;
            }
            mid = left + ((right-left) >> 1);
            if (check(mid)) left = mid;
            else right = mid;
        }
        return 0;
    }
};
