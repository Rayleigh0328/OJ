class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if (nums.size() == 0) return -1;
        if (nums.size() == 1) return 0;
        int pos = 0;
        for (int i=0; i<nums.size();++i) 
        	if (nums[pos] < nums[i]) pos = i;
        for (int i=0; i<nums.size();++i)
        	if (i!=pos && nums[pos] < 2*nums[i]) return -1;
        return pos;
    }
};
