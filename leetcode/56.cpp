bool cmp(const vector<int>& x, const vector<int>&y){
    return x[0] < y[0];
}

class Solution {
    
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
    
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> result;
        vector<int> tmp;
        for(auto& e : intervals){
            tmp = e;
            while (!result.empty() && overlap(result.back(), tmp)){
                tmp = merge(result.back(), tmp);
                result.pop_back();
            }
            result.push_back(tmp);
        }
        return result;
    }
};
