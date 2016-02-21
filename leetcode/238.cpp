class Solution {
public:
    vector<int> productExceptSelf(vector<int>& a) {
        int n = a.size();
        vector<int> ans(n,1);
        for (int i=1;i<n;++i)
            ans[i] = ans[i-1] * a[i-1];
        int prod = 1;
        for (int i=a.size()-1;i>=0;--i)
        {
            ans[i] *= prod;
            prod *= a[i];
        }
        return ans;
    }
};