class Solution {
public:
    int missingNumber(vector<int>& a) {
        int n = a.size();
        int s = (n+1)*n/2;
        int tot= 0;
        for (int i=0;i<a.size();++i)
            tot+=a[i];
        return s-tot;
    }
};