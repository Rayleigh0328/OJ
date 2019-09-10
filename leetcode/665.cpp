class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if (nums.size() <=2) return true;
        int count = 0;
        for (int i=0; i<nums.size()-1;++i)
            if (nums[i] > nums[i+1]) {
                // decrease i or increase i+1
                // decrease i is more prefered
                if (i == 0 || nums[i-1] <= nums[i+1]) {}
                else nums[i+1] = nums[i];
                if (++count >=2) return false;
            }
                
        return true;
    }
};
