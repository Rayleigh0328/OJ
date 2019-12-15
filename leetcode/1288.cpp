class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& a) {
        if (a.empty()) return 0;
        
        sort(a.begin(), a.end(), [](const vector<int> &x, const vector<int> &y){
            if (x[0] < y[0]) return true;
            if (x[0] > y[0]) return false;
            return (x[1] > y[1]);
        });
        int n = a.size();
        int result = n;
        int right = a[0][1];
        for (int i=1;i<n;++i)
            if (a[i][1] <= right) --result;
            else right = a[i][1];
        return result;
    }
};
