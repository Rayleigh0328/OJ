class Solution {
public:
    int superEggDrop(int k, int n) {
        // solution 1
        // k is the number of eggs, n is number of floor
        // f[k, l, r] denotes min moves needed to determine hardness from l to r inclusive with k eggs
        // drop at floor p in [l,r] if break then f[k-1, l, p-1] else f[k,p+1, r]
        // f[k,l,r] = 1 + min{ max{f[k-1, l, p-1], f[k,p+1,r]} } l <= p <= r
        
        // first optimization: symmetricity, f[k, i,j] = f[k, i+x, j+x], 
        // i.e. only the difference between i,j matters
        // f[k,l,r] can be simplified as f[k,len] where len = r-l
        // f[k, len] = 1 + min {max{f[k-1,p-1], f[k,len-p]}} 1 <= p <= len
        
        // second optimization, think of f as a function of p
        // f[k-1, p-1] is incresing while f[k, len-p] is decreasing 
        // which indicates the min point will be obtained where f[k-1, p-1] ~= f[k, len - p]
        // ~- denotes roughly equal, the function g(p) = f[k-1, p-1] - f[k, len-p] is increasing
        // it is possible to binary search the point p0 where g(p0) ~= 0
        // complexity is O(k*n*log n)
        
        const int inf = (1<<28);
        int f[k+1][n+1];
        // init f
        memset(f, 0, sizeof f);
        for (int i=0;i<=k;++i)
            for (int j=1;j<=n;++j)
                f[i][j] = inf;
        for (int j=0;j<=n;++j) f[1][j] = j;
        
        // dp, use binary search to find optimal point
        int left, right, mid, part1, part2;
        for (int i=2; i<=k;++i){
            f[i][1] = 1;
            for (int j=2; j<=n;++j){
                // f[i][j] = 1 + min{ max {f[i-1][p-1], f[i][j-p]} }
                left = 0, right = j;
                while (left <= right){
                    mid = (left + right)/2;
                    if (mid == 0) part1 = 0;
                    else part1 = f[i-1][mid-1];
                    part2 = f[i][j-mid];
                    f[i][j] = min(f[i][j], max(part1, part2) + 1);
                    if (part1 < part2) left = mid + 1;
                    else right = mid -1;
                }
            }
        }
        
        return f[k][n];
    }
};
