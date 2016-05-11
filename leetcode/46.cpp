class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<int> ind;
        ind.clear();
        for (int i=0;i<nums.size();++i)
            ind.push_back(i);
        vector<vector<int>> ans;
        ans.clear();
        do
        {
            ans.push_back(vector<int>());
            for (int i=0;i<nums.size();++i)
                ans[ans.size()-1].push_back(nums[ind[i]]);
        }while (next_permutation(ind.begin(), ind.end()));
        return ans;
    }
};