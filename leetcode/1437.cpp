class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        vector<int> a;
        for (int i=0;i<nums.size();++i)
            if (nums[i] == 1) a.push_back(i);
        for (int i=1;i<a.size();++i)
            if (a[i]-a[i-1] <= k) return false;
        return true;
    }
};
