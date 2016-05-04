class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        int cnt[32];
        for (int i=0;i<32;++i) cnt[i] = 0;
        for (int i=0;i<nums.size();++i)
            for (int j=0;j<32;++j)
                if ((nums[i] & (1u<<j))>0) ++cnt[j];
        unsigned ans = 0;
        for (int i=0;i<32;++i)
            if (cnt[i] % 3 == 1) ans |= (1u << i);
        return ans;
    }
};