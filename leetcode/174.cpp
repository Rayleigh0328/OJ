class Solution {
    
    bool check(int init_health, vector<vector<int>> &a){
        int n = a.size();
        int m = a[0].size();
        vector<vector<int>> f(n,vector<int>(m,0));
        f[0][0] = init_health + a[0][0];
        if (f[0][0] <= 0) return false;
        
        for (int j=1;j<m;++j) 
            if (f[0][j-1] >0) f[0][j] = max(0, f[0][j-1] + a[0][j]);
        
        for (int i=1;i<n;++i) 
            if (f[i-1][0] >0) f[i][0] = max(0, f[i-1][0] + a[i][0]);
        
        for (int i=1;i<n;++i)
            for (int j=1;j<m;++j){
                if (f[i][j-1] > 0) f[i][j] = max(0, f[i][j-1] + a[i][j]);
                if (f[i-1][j] > 0) f[i][j] = max(f[i][j], f[i-1][j] + a[i][j]);
            }
        for (int i=0;i<n;++i){
            for (int j=0;j<m;++j){
                cout << f[i][j] << " ";
            }
            cout << endl;
        }
        return (f[n-1][m-1] > 0);
    }
    
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int left = 1, right = (1<<30), mid;
        while (left < right){
            if (left + 1 == right) return left;
            if (left + 2 == right){
                if (check(left, dungeon)) return left;
                return left+1;
            }
            
            mid = left + ((right-left) >> 1);
            if (check(mid,dungeon)) right = mid+1;
            else left = mid + 1;
        }
        return -1;
    }
};
