class Solution {    
public:
    vector<int> xorQueries(vector<int>& a, vector<vector<int>>& queries) {
        int n = a.size();
        vector<vector<int>> sum(n+1, vector<int>(32, 0));
        for (int i=0;i<n;++i){
            int x = a[i];
            for (int j = 0; j<32; ++j){
                sum[i+1][j] = sum[i][j];
                if (x & (1<<j)) ++sum[i+1][j];
            }
        }
        vector<int> result;
        for (auto &query : queries){
            int left = query[0];
            int right = query[1];
            int tmp = 0;
            for (int j=0;j<32;++j)
                tmp += (1 << j) * ((sum[right+1][j] - sum[left][j]) & 1);
            result.push_back(tmp);
        }
        return result;
    }
};
