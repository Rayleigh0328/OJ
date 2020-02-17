class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        const int n = events.size();
        sort(events.begin(), events.end(), [](const vector<int>&x, const vector<int>&y){
            if (x[0] < y[0]) return true;
            if (x[0] > y[0]) return false;
            return x[1] < y[1];
        });
        multiset<int> end_set;
        int cur_id = 0;
        int result = 0;
        for (int i=1;i<=100000;++i){
            // update end_to_id
            while (cur_id < n && events[cur_id][0] <= i && events[cur_id][1] >= i) {
                end_set.emplace(events[cur_id][1]);
                ++cur_id;
            }
            while (!end_set.empty() && *end_set.begin()<i)
                end_set.erase(end_set.begin());
            if (!end_set.empty()){
                ++result;
                end_set.erase(end_set.begin());
            }
        }
        return result;
    }
};
