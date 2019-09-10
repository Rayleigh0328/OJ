class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        vector<int> f(nums.size());
        f[0] = 1;
        for (int i=1; i<nums.size();++i)
            if (nums[i] > nums[i-1]) f[i] = 1 + f[i-1];
            else f[i] = 1;
        int ans = 0;
        for (int i=0;i<f.size();++i) 
            if (f[i] > ans) ans = f[i];
        return ans;
    }
};
