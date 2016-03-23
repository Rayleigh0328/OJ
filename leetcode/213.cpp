class Solution {
private:
    int rob_simp(vector<int>& nums) {
        vector<int> f;
        for (int i=0;i<nums.size();++i)
        {
            f.push_back(nums[i]);
            int tmp = 0;
            tmp = max(tmp, ((i-2>=0)?f[i-2]:0));
            tmp = max(tmp, ((i-3>=0)?f[i-3]:0));
            tmp = max(tmp, ((i-3>=0)?f[i-3]:0));
            f[i] += tmp;
        }
        
        int result = 0;
        for (int i=0;i<f.size();++i)
            result = max(result,f[i]);
        return result;
    }
    
    int solve(int left, int right, vector<int>& a)
    {
        if (right < left) return 0;
        vector<int> cut;
        cut.clear();
        for (int i=left; i<=right;++i)
            cut.push_back(a[i]);
        return rob_simp(cut);
    }
public:
    int rob(vector<int>& a) 
    {
        if (a.empty()) return 0;
        int n = a.size();
        return max(solve(1,n-1,a), a[0] + solve(2,n-2,a));
    }
};

