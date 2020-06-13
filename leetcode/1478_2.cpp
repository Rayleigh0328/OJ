class Solution {
    typedef long long LL;
    static const int max_size = 110;
    static const LL inf = (1ll<<40);
    
    vector<int> a;
    int n;
    
    int dist(int id1, int id2){
        int ans = a[id2] - a[id1];
        if (ans < 0) return -ans;
        return ans;
    }
    
public:
    int minDistance(vector<int>& houses, int target) {
        a = houses;
        n = a.size();
        
        sort(a.begin(), a.end());
        
        // for (auto x : a) printf("%d ", x); printf("\n");
        
        LL f[max_size][max_size][max_size];
        for (int i=0;i<max_size;++i)
            for (int j=0;j<max_size;++j)
                for (int k=0;k<max_size;++k)
                    f[i][j][k] = inf;
        
        // boundary f[i][1][i]
        f[0][1][0] = 0;
        for (int i=1;i<n;++i)
            f[i][1][i] = f[i-1][1][i-1] + dist(i-1,i) * i;
        
        // printf("finish init\n");
        
        for (int i=0;i<n;++i)
            for (int j=1;j<=target;++j){
                
                if (j > i+1) break;
                // printf("solve %d, %d\n", i,j);
                
                // case 1: put a mailbox on house[i]
                if (j > 1){
                    LL total_dist = 0;
                    int split_index = i;
                    for (int k=i-1;k>=0;--k){
                        while (dist(split_index,k) > dist(split_index, i)) {
                            total_dist += dist(split_index,i);
                            --split_index;
                        }
                        // printf("\t%d %d\n", split_index, total_dist);
                        f[i][j][i] = min(f[i][j][i], f[split_index][j-1][k] + total_dist);
                    }
                }
                // case 2: no mailbox on house[i]
                for (int k=0;k<i;++k)
                    f[i][j][k] = min(f[i][j][k] , f[i-1][j][k] + dist(k,i));
            }
        
        // cout << f[2][1][1] << endl;
        
        LL result = inf;
        for (int k=0;k<n;++k)
            result = min(result, f[n-1][target][k]);
        return result;
    }
};
