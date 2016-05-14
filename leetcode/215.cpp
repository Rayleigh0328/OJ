class Solution {
private:
    int solve(int left, int right, int rank, vector<int>& a)
    {
        int pivot = a[right];
        int ad = left;
        for (int i=left; i<right; ++i)
            if (a[i] < pivot) swap(a[i], a[ad++]);
        swap(a[ad], a[right]);
        
        if (ad - left + 1 == rank) return a[ad];
        if (ad - left + 1 > rank)
            return solve(left, ad-1, rank, a);
        else
            return solve(ad + 1, right, rank - (ad-left+1), a);
    }
    
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        if (nums.empty()) return -1;
        int m = nums[0];
        for (int i=0;i<nums.size();++i) m = max(m, nums[i]);
        for (int i=0;i<nums.size();++i) nums[i] = m - nums[i];
        
        return m - solve(0, nums.size()-1, k, nums);
    }
};