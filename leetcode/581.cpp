class Solution {
public:
    int findUnsortedSubarray(vector<int>& a) {
        vector<int> b = a;
        sort(b.begin(), b.end());
        int i=0;
        while (i<a.size() && b[i] == a[i]) ++i;
        if (i==a.size()) return 0;
        int j=a.size()-1;
        while (j>=0 && b[j] == a[j]) --j;
        return j-i+1;
    }
};
