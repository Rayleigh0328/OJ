class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &x, const vector<int> &y){return x[1] < y[1];});
        if (intervals.empty()) return 0;
        int cur = intervals[0][1];
        int ans = 0;
        for (int i=1;i<intervals.size();++i)
            if (cur > intervals[i][0]) ++ans;
            else cur = intervals[i][1];
        return ans;
    }
};
