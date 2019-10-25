class Solution {
public:
    int removeElement(vector<int>& a, int val) {
        int tail = a.size()-1;
        while (tail >= 0 && a[tail] == val) --tail;
        for (int i=0;i<tail;++i){
            if (a[i] == val){
                a[i] = a[tail];
                --tail;
            }
            while (tail >= 0 && a[tail]==val) -- tail;
        }
        return tail + 1;
    }
};
