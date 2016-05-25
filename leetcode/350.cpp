class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        map<int, int> m1;
        map<int, int> m2;
        
        for (int i=0;i<nums1.size();++i)
            if (m1.find(nums1[i]) != m1.end()) ++m1[nums1[i]];
            else m1.emplace(nums1[i],1);

        for (int i=0;i<nums2.size();++i)
            if (m2.find(nums2[i]) != m2.end()) ++m2[nums2[i]];
            else m2.emplace(nums2[i],1);
        
        vector<int> ans;
        ans.clear();
        
        map<int, int>::iterator it, pos_it;
        int cnt;
        for (it = m1.begin(); it != m1.end(); ++it)
        {
            pos_it = m2.find(it->first);
            
            if (pos_it != m2.end())
                cnt = min(it->second, pos_it->second);
            else
                cnt = 0;
            for (int i=0;i<cnt;++i)
                ans.push_back(it->first);
        }
        
        return ans;
    }
};