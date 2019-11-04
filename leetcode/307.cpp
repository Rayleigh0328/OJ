struct Bit{
    int n;
    vector<int> bit;
    vector<int> a;
    
    Bit(){}
    
    Bit(const vector<int> &data){
        n = data.size()+1;
        a = vector<int>(n);
        bit = vector<int>(n);
        bit[0] = a[0] = 0;
        for (int i=0;i<n-1;++i) bit[i+1] = a[i+1] = data[i];
        for (int i=1;i<n;++i)
            if (i + low(i) < n)
                bit[i + low(i)] += bit[i];
    }
    
    int low(int x){
        return x & -x;
    }
    
    void update(int index, int delta){
        // note the index is the index in data
        int x = index + 1;
        a[x] += delta;
        while (x < n){
            bit[x] += delta;
            x += low(x);
        }
    }
    
    int prefix_sum(int x){
        int ans = 0;
        while (x > 0){
            ans += bit[x];
            x -= low(x);
        }
        return ans;
    }
    
    int range_sum_query(int left, int right){
        // note that here left, right are index in data
        return prefix_sum(right+1) - prefix_sum(left);
    }
};

class NumArray {
    Bit bit;
public:
    NumArray(vector<int>& a) {
        bit = Bit(a);
    }
    
    void update(int i, int val) {
        bit.update(i,val-bit.a[i+1]);
    }
    
    int sumRange(int i, int j) {
        return bit.range_sum_query(i,j);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
