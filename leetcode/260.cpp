class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        set<int> s;
        s.clear();
        set<int>::const_iterator it;
        for (int i=0;i<nums.size();++i)
            if ((it = s.find(nums[i]))==s.end())
                s.insert(nums[i]);
            else 
                s.erase(it);
                
        vector<int> ans;
        ans.clear();
        for (set<int>::iterator i=s.begin(); i!=s.end();++i)
            ans.push_back(*i);
        return ans;
    }
};