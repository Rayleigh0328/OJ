class Solution {
public:
    vector<int> shuffle(vector<int>& a, int n) {
        vector<int> result(2*n);
        for (int i=0;i<n;++i) result[2*i] = a[i];
        for (int i=n;i<2*n;++i) result[2*(i-n) + 1] = a[i];
        return result;
    }
};
