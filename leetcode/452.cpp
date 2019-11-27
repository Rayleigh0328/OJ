class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& a) {
        if (a.empty()) return 0;
        int n = a.size();
        sort(a.begin(), a.end(), [](vector<int>&x,vector<int>&y){return x[1] < y[1];});
        int pos = a[0][1];
        int ans = 1;
        for (int i=0;i<n;++i)
            if (a[i][0]>pos){
                ++ans;
                pos = a[i][1];
            }
        return ans;
    }
};
