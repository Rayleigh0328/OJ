class Solution {
public:
    int findUnsortedSubarray(vector<int>& a) {
        int n = a.size();
        int left = -1, right = -1;
        int min = a[n-1];
        for (int i=n-1;i>=0;--i){
            if (a[i] > min) left = i;
            else min = a[i];
        }
        if (left == -1) return 0;
        int max = a[0];
        for (int i=0;i<n;++i){
            if (a[i]<max) right = i;
            else max = a[i];
        }
        return right - left + 1;
    }
};
