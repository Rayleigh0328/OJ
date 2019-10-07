class Solution {
    
public:
    int numSubmatrixSumTarget(vector<vector<int>>& g, int target) {
        int n = g.size();
        int m = g[0].size();
        
        // sum[i][j][k] is the sum of element for row i from j column to k column
        vector<vector<vector<int>>> sum(n, vector<vector<int>>(m, vector<int>(m)));
       
        for (int i=0;i<n;++i)
            for (int left = 0; left < m; ++left){
                sum[i][left][left] = g[i][left];
                for (int right = left + 1; right < m; ++right)
                    sum[i][left][right] = sum[i][left][right-1] + g[i][right];
            }
        
        
        int ans = 0;
        unordered_map<int, int> sum_count;
        int block_sum;
        for (int left = 0; left < m; ++left)
            for (int right = left; right < m; ++right){
                
                sum_count.clear();
                sum_count[0] = 1;
                block_sum = 0;
                for (int row = 0; row < n; ++row){
                    block_sum += sum[row][left][right];
                    if (sum_count.find(block_sum-target) != sum_count.end())
                        ans += sum_count[block_sum - target];
                    if (sum_count.find(block_sum) == sum_count.end())
                        sum_count[block_sum] = 1;
                    else
                        ++sum_count[block_sum];
                }
            }
        
        return ans;
    }
};
