class Solution {
public:
    int subarraySum(vector<int>& a, int k) {
        unordered_map<int,int> sum_count;
        sum_count[0] = 1;
        int n = a.size();
        int sum = 0;
        int ans = 0;
        for (int i=0;i<n;++i){
            sum += a[i];
            if (sum_count[sum-k] != NULL) ans += sum_count[sum-k];
            ++sum_count[sum];
        }
        return ans;
    }
};
