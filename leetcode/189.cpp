class Solution {
public:
    void rotate(vector<int>& a, int k) {
        vector<int> cp(a);
        for (int i=0;i<a.size();++i)
            a[(i+k)%a.size()] = cp[i];
    }
};