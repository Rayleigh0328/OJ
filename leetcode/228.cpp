class Solution {
public:
    vector<string> summaryRanges(vector<int>& a) 
    {
        vector<string> ans;
        ans.clear();
        int left = 0, right;
        while (left < a.size())
        {
            right = left;
            while (right < a.size() -1 && a[right+1] - a[right] == 1) ++right;
            
            if (left== right)
            {
                ans.push_back(to_string(a[left]));
            }
            else
            {
                ans.push_back(to_string(a[left])+"->"+to_string(a[right]));
            }
            
            left = right + 1;
        }
        
        return ans;
    }
};