class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int>tmp;
        tmp.clear();
        for (int i=0; i != nums.size(); ++i)
            if (nums[i]!=val) tmp.push_back(nums[i]);
        for (int i=0; i != tmp.size(); ++i)
            nums[i] = tmp[i];
        return tmp.size();
    }
};