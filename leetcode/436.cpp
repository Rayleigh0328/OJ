class Solution {
    map<int, int> start_to_index;
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        for (int i=0;i<intervals.size();++i){
            start_to_index.emplace(intervals[i][0], i);
        }
        vector<int> ans;
        for (auto &e : intervals){
            if (start_to_index.upper_bound(e[1]-1) == start_to_index.end()) ans.push_back(-1);
            else ans.push_back(start_to_index.upper_bound(e[1]-1)->second);
        }
        return ans;
    }
};
