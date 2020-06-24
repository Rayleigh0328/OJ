class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int> a;
        for (int i=0;i<n;++i)
            a.push_back(start + 2*i);
        int result = 0;
        for (auto x : a)
            result = (result ^ x);
        return result;
    }
};
