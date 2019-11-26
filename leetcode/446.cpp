class Solution {
    static const int max_size = 1005;
    
    unordered_map<long long, vector<int>> k_to_pv;
    int f[max_size][max_size];
    int n;
public:
    int numberOfArithmeticSlices(vector<int>& a) {
        n = a.size();
        for (int i=0;i<n;++i){
            for (int j=0;j<i;++j){
                long long key = 2ll * a[j] - a[i];
                if (k_to_pv.find(key) == k_to_pv.end()) continue;
                else {
                    for (int pos : k_to_pv[key])
                        if (pos < j) f[i][j] += 1 + f[j][pos];
                }
            }
            k_to_pv[a[i]].push_back(i);
        }
        
        int ans = 0;
        for (int i=0;i<n;++i)
            for (int j=0;j<i;++j)
                ans += f[i][j];
        return ans;
    }
};
