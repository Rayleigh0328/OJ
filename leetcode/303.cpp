class NumArray {
private:
    vector<int> a;
public:
    NumArray(vector<int> &nums)
    {
        if (!nums.empty()) a.push_back(nums[0]);
        for (int i=1; i<nums.size();++i)
            a.push_back(a[a.size()-1] + nums[i]);
    }

    int sumRange(int i, int j) 
    {
        return a[j] - (i==0?0:a[i-1]);
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);