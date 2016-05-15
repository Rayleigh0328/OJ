class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int cnt[3];
         cnt[0] = cnt[1] = cnt[2] = 0;
        for (int i=0;i<nums.size();++i)
            ++cnt[nums[i]];
        for (int i=0;i<cnt[0];++i)
            nums[i] = 0;
        for (int i=0;i<cnt[1];++i)
            nums[i + cnt[0]] = 1;
        for (int i=0;i<cnt[2];++i)
            nums[i + cnt[0] + cnt[1]] = 2;
    }
};