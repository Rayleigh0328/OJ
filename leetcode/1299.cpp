class Solution {
public:
    vector<int> replaceElements(vector<int>& a) {
        vector<int> b(a);
        for (int i=b.size()-2;i>=0;--i)
            b[i] = max(b[i], b[i+1]);
        b.push_back(-1);
        b.erase(b.begin());
        return b;
    }
};
