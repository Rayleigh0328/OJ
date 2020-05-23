class Solution {
    
    vector<int> get_intersection(const vector<int> &x, const vector<int> &y){
        if (x[1] < y[0]) return {};
        if (y[1] < x[0]) return {};
        
        return {max(x[0],y[0]), min(x[1],y[1])};
    }
    
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& a, vector<vector<int>>& b) {
        
        int p1 = 0, p2 = 0;
        vector<vector<int>> result;
        
        while (p1 < a.size() && p2 < b.size()){
            vector<int> tmp = get_intersection(a[p1], b[p2]);
            if (!tmp.empty()) result.push_back(tmp);
            if (a[p1][1] > b[p2][1]) ++p2;
            else ++p1;
        }
        
        return result;
    }
};
