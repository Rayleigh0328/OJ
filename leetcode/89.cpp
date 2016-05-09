class Solution {
public:
    vector<int> grayCode(int n) 
    {
        vector<int> ans;
        ans.clear();
        if (n < 0) return ans;
        
        ans.push_back(0);
        if (n == 0) return ans;
        ans.push_back(1);
        if (n == 1) return ans;
        
        for (int i=1;i<n;++i)
            for (int j=ans.size()-1; j>=0; --j)
                ans.push_back(ans[j] + (1<<i));
        
        return ans;
    }
};