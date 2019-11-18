bool cmp_people(const vector<int>&x, vector<int>&y){
    if (x[0] > y[0]) return true;
    if (x[0] < y[0]) return false;
    return x[1] < y[1];
}

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp_people);
        vector<vector<int>> result;
        for (auto &p : people){
            auto it = result.begin();
            for (int i=0;i<p[1];++i) ++it;
            result.insert(it, p);
        }
        return result;
    }
};
