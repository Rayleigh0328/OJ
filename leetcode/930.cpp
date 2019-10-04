class Solution {
public:
    int numSubarraysWithSum(vector<int>& a, int target) {
        int n = a.size();
        unordered_map<int,int> sum_count;
        sum_count.emplace(0,1);
        
        int ans = 0;
        int sum = 0;
        for (int i=0;i<n;++i){
            sum += a[i];
            if (sum_count.find(sum-target)!=sum_count.end())
                ans += sum_count[sum-target];
            if (sum_count.find(sum) == sum_count.end())
                sum_count.emplace(sum,1);
            else 
                ++sum_count[sum];
        }
        return ans;
    }
};
