class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        set<int> s1;
        s1.clear();
        set<int> s2;
        s2.clear();
        
        for (int i=0;i<nums1.size();s1.insert(nums1[i++]));
        for (int i=0;i<nums2.size();s2.insert(nums2[i++]));
        
        vector<int> ans;
        ans.clear();
        
        set<int>::iterator it;
        for (it = s1.begin(); it != s1.end(); ++it)
            if (s2.find(*it) != s2.end())
                ans.push_back(*it);
        
        return ans;
    }
};