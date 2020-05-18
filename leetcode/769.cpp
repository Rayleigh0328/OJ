class Solution {
public:
    int maxChunksToSorted(vector<int>& a) {
        int left=0, right=0, result=0;
        set<int> s;
        while (left < a.size()){
            s.clear();
            s.emplace(a[left]);
            right = left+1;
            while (!(*s.begin()==left && *s.rbegin()==right-1)) {
                s.emplace(a[right++]);
            }
            left = right;
            ++result;
        }
        return result;
    }
};
