class Solution {
public:
    bool checkSubarraySum(vector<int>& a, int k) {
        if ( k < 0) k = -k;
        
        if (a.size() < 2) return false;
        for (int i=1;i<a.size();++i)
            if (a[i]==0 && a[i-1]==0) return true;
        
        if (k == 0) return false;
        
        int n = a.size();
        unordered_set<int> sum_set;
        sum_set.emplace(0);
        int sum = a[0];
        for (int i=1; i<n; ++i){
            sum += a[i];
            if (sum_set.find((sum-k)%k) != sum_set.end()) return true;
            sum_set.emplace((sum - a[i])%k);
        }
        return false;
    }
};
