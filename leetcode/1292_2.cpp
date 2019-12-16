class Solution {
    vector<vector<int>> g, f;
    int n,m;
    int limit;
    
    void compute_f(){
        f = vector<vector<int>> (n, vector<int>(m,0));
        f[0][0] = g[0][0];
        for (int j=1;j<m;++j) f[0][j] = f[0][j-1] + g[0][j];
        for (int i=1;i<n;++i) f[i][0] = f[i-1][0] + g[i][0];
        for (int i=1;i<n;++i)
            for (int j=1;j<m;++j)
                f[i][j] = g[i][j] + f[i-1][j] + f[i][j-1] - f[i-1][j-1];
    }
    
    bool check(int len){
        for (int i=0;i+len-1<n;++i)
            for (int j=0;j+len-1<m;++j){
                int tmp = f[i+len-1][j+len-1];
                tmp -= (i==0?0:f[i-1][j+len-1]);
                tmp -= (j==0?0:f[i+len-1][j-1]);
                tmp += (i==0||j==0?0:f[i-1][j-1]); 
                if (tmp <= limit) return true;
            }
        return false;
    }
    
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        limit = threshold;
        g = mat;
        if (g.empty() || g[0].empty()) return 0;
        n = g.size();
        m = g[0].size();
        
        compute_f();
        
        int left = 1, right = min(n,m)+1, mid;
        while (true){
            if (left + 1 == right){
                if (check(left)) return left;
                else return 0;
            }
            if (left + 2 == right){
                if (check(left+1)) return left+1;
                if (check(left)) return left;
                return 0;
            }
            mid = left + ((right - left)>>1);
            if (check(mid)) left = mid;
            else right = mid;
        }
        
    }
};
