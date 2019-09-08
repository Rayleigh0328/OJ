class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> index;
        index.clear();
        for (int i=0;i<nums.size();++i)
        {
            if (index.find(nums[i]) != index.end())
            {
                vector<int> result;
                result.clear();
                result.push_back(index[nums[i]] + 1);
                result.push_back(i + 1);
                return result;
            }
            
            index.emplace(target - nums[i], i);
        }
    }
};