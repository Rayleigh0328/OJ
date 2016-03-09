class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        int p1=0,p2=0;
        while (p2 < a.size())
        {
            while (p1 > 1 && p2<a.size() && a[p2] == a[p1-1] && a[p2] == a[p1-2]) ++p2;
            if (p2 < a.size()) a[p1++] = a[p2++];
        }
        return p1;
    }
};