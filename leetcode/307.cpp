class NumArray {
public:
    NumArray(vector<int> &nums) {
        int n = nums.size();
        len = 1;
        while (len < n) len = len << 1;
        
        a = new int [2*len];
        for (int i=0;i<2*len;++i)
            a[i] = 0;
        
        for (int i=0;i<n;++i)
            a[len+i] = nums[i];
        for (int i=len-1; i>0;--i)
            a[i] = a[i<<1] + a[i<<1 | 1];
    }

    void update(int i, int val) {
        int diff = val - a[len+i];
        int ad = len+i;
        while (ad > 0)
        {
            a[ad] += diff;
            ad = ad >> 1;
        }
        //for (int i=0;i<2*len;++i) cout << a[i] << " "; cout << endl;
    }

    int sumRange(int left, int right) {
        return -get_sum(1,len, left) + get_sum(1,len, right) + a[len+left];
        
    }
private:
    int* a;
    int len;
    
    int get_sum(int cur, int len, int k)
    {
        
        if (k == len - 1) 
            return a[cur];
        if (k < (len >> 1)) return get_sum(cur<<1, len>>1, k);
        else
            return a[cur<<1] + get_sum(cur<<1 | 1, len>>1, k-(len>>1));
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);