
class Solution {
    const int inf = (1<<25);

public:
    int cherryPickup(vector<vector<int>>& g) {
        int n = g.size();
        int m = g[0].size();

        for (int i=0;i<n;++i)
            for (int j=0;j<m;++j)
                if (g[i][j] == -1) 
                    g[i][j] = -inf;

        // for (int i=0;i<n;++i){
        //     for (int j=0;j<m;++j) 
        //         if (g[i][j] == -inf) cout << "#"; 
        //         else cout << g[i][j];
        //     cout << endl;     
        // }

        vector<vector<vector<int>>> f(n+m, vector<vector<int>>(n, vector<int>(n, -inf)));
        f[0][0][0] = g[0][0];
        for (int step = 1; step <= n+m-2; ++step)
            for (int x1 = 0; x1 <= min(n-1, step); ++x1)
                for (int x2 = 0; x2 <= min(n-1, step); ++x2){

                    int y1 = step - x1;
                    int y2 = step - x2;
                    if (y1 >= m || y2 >=m) {
                        f[step][x1][x2] = -inf;
                        continue;
                    }

                    if (x1 == x2) f[step][x1][x2] = g[x1][y1];
                    else f[step][x1][x2] = g[x1][y1] + g[x2][y2];
                    
                    int pre = -inf;  
                    if (x1 > 0 && x2 > 0) pre = max(pre, f[step-1][x1-1][x2-1]);
                    if (x1 > 0) pre = max(pre, f[step-1][x1-1][x2]);
                    if (x2 > 0) pre = max(pre, f[step-1][x1][x2-1]);
                    pre = max(pre, f[step-1][x1][x2]);

                    f[step][x1][x2] += pre;
                    if (f[step][x1][x2] < 0) f[step][x1][x2] = -inf;

                    // printf("step: %d, loc1: (%d, %d), loc2: (%d, %d) max is %d\n", step, x1, y1, x2, y2, f[step][x1][x2]);
                }
        return (f[n+m-2][n-1][n-1] < 0?0:f[n+m-2][n-1][n-1]);
    }
};
