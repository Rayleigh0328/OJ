bool overlap(const vector<int>& a, const vector<int>& b){
    if (a[1] < b[0] || b[1] < a[0]) return false;
    return true;
}

vector<int> merge(const vector<int>&a, const vector<int>& b){
    vector<int> result;
    result.push_back(min(a[0],b[0]));
    result.push_back(max(a[1],b[1]));
    return result;
}

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& ni) {
        vector<vector<int>> result{ni};
        vector<int> tmp;
        for (auto &e : intervals){
            tmp = result.back();
            if (overlap(tmp, e)){
                result.pop_back();
                result.push_back(merge(tmp,e));
            }
            else if (tmp[1] < e[0]){
                result.push_back(e);
            }
            else {
                result.pop_back();
                result.push_back(e);
                result.push_back(tmp);
            }
        }
        return result;
    }
};
