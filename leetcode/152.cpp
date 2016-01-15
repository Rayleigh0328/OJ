class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        int *p = new int [nums.size()];
        int *n = new int [nums.size()];
        for (int i=0;i<nums.size();++i)
            p[i] = n[i] = nums[i];
        for (int i=1;i<nums.size();++i)
        {
            p[i] = max(p[i], p[i-1] * nums[i]);
            p[i] = max(p[i], n[i-1] * nums[i]);
            n[i] = min(n[i], p[i-1] * nums[i]);
            n[i] = min(n[i], n[i-1] * nums[i]);
        }
        int result = p[0];
        for (int i=0;i<nums.size();++i)
            result = max(result, p[i]);
        return result;
    }
};