class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& td) {
        vector<vector<int>> result;
        for (auto &interval : intervals){
            if (interval[1] <= td[0])
                result.push_back(interval);
            if (interval[0] >= td[1])
                result.push_back(interval);
            if (td[0] <= interval[0] && interval[1] <= td[1]) continue;
            if (interval[0] < td[0] && td[0] < interval[1])
                result.push_back({interval[0], td[0]});
            if (interval[0] < td[1] && td[1] < interval[1])
                result.push_back({td[1], interval[1]});
        }
        return result;
    }
};
