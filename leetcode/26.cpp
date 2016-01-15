class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int first=0, second=1;
        if (nums.empty()) return 0;
        for (;second < nums.size(); ++second)
            if (nums[second] != nums[first])
                nums[++first] = nums[second];
        return first+1;
    }
};