class Solution {
public:
    int peakIndexInMountainArray(vector<int>& a) {
        int left = 0, right = a.size();
        int lmid, rmid, pos=0;
        while (left < right){
            if (left + 1 == right){
                return left;
            }
            lmid = left + ((right - left) >> 1);
            rmid = lmid + ((right - lmid) >> 1);
            
            if (a[lmid] > a[rmid])
                right = rmid;
            else 
                left = lmid;
        }
        return -1;
    }
};
