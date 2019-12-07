class Solution {
public:
    int removeElement(vector<int>& a, int val) {
        int p1 = 0, p2 = 0;
        while (p2 < a.size()){
            if (a[p2] != val) a[p1++] =a[p2];
            ++p2;
        }
        return p1;
    }
};
