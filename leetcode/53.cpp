class Solution {
private:
    int inf = 1<< 30;
public:
    int maxSubArray(vector<int>& nums) 
    {
        vector<int> f(nums);
        for (int i=1;i<f.size();++i)
            f[i] += (f[i-1] > 0)?f[i-1]:0;
        int ans = -inf;
        for (int i=0;i<f.size(); ++i)
            ans = max(ans, f[i]);
        return ans;
    }
};