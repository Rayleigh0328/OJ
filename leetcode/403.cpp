class Solution {
    
    static const int MAX_SIZE = 1111;
    static const int INF = (1<<30);
    
    int n;
    int f[MAX_SIZE][MAX_SIZE];
    vector<int> a;
    
    int find_ind(int val){
        int left = 0, right = a.size(), mid;
        while (left < right){
            mid = left + ((right-left) >> 1);
            if (a[mid] == val) return mid;
            else if (a[mid] < val) left = mid + 1;
            else right = mid;
        }
        return -1;
    }
    
    int solve(int cur_ind, int prev_ind){
        
        if (f[cur_ind][prev_ind] != -1) return f[cur_ind][prev_ind];
        
        f[cur_ind][prev_ind] = INF;
        int dist = a[cur_ind] - a[prev_ind];
        
        for (long long d = dist-1; d <= dist+1; ++d){
            int ind = find_ind(a[prev_ind] - d);
            if (ind != -1)
                f[cur_ind][prev_ind] = min(f[cur_ind][prev_ind], solve(prev_ind,ind) + 1);
        }
        
        return f[cur_ind][prev_ind];
    }
    
public:
    bool canCross(vector<int>& stones) {
        
        if (stones[1] != 1) return false;
        a = stones;
        n = a.size();
        
        // init
        for (int i=0; i<MAX_SIZE; ++i)
            for (int j=0;j<MAX_SIZE; ++j)
                f[i][j] = -1;
        for (int j=0;j<MAX_SIZE;++j) f[0][j] = f[1][j] = INF;
        f[1][0] = 1;
        
        // dp
        // solve(7,6);
        for (int j=1;j<n-1;++j) solve(n-1,j);
        
        // get solution
        int ans = INF;
        for (int j=0;j<n;++j)
            if (f[n-1][j] != -1)
                ans = min(ans, f[n-1][j]);
        return (ans < INF);
    }
};
