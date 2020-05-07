class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> a,b;
        for (int i=0;i<nums.size();++i)
            if (i&1) b.push_back(nums[i]);
            else a.push_back(nums[i]);
        
        vector<int> result;
        for (int i=0;i<a.size();++i)
            for (int j=0;j<a[i];++j)
                result.push_back(b[i]);
        return result;
    }
};
