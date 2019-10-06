class Solution {
public:
    int minCostToMoveChips(vector<int>& a) {
        int count= 0;
        int n = a.size();
        for (int i=0;i<n;++i)
            if (a[i] & 1) ++count;
        return min(count, n - count);
    }
};
