class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        unordered_set<int>::iterator it;
        
        s.clear();
        for (int i=0;i<nums.size();++i)
            s.emplace(nums[i]);
            
        int ans = 0;
        while (!s.empty())
        {
            int mid = *s.begin();
            s.erase(s.begin());
            int len = 1;
            
            int cur = mid;
            while ((it = s.find(cur-1)) != s.end())
            {
                ++len;
                --cur;
                s.erase(it);
            }
        
            cur = mid;
            while ((it = s.find(cur+1)) != s.end())
            {
                ++len;
                ++cur;
                s.erase(it);
            }
            ans = max(ans,len);
        }
        return ans;
    }
    
};