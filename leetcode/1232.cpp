class Solution {
    
    bool check(vector<int>&a, vector<int>&b, vector<int>&c){
        int x1 = c[0]-a[0];
        int y1 = c[1]-a[1];
        int x2 = b[0]-a[0];
        int y2 = b[1]-a[1];
        return (x1 * y2 - x2*y1 == 0);
    }
    
public:
    bool checkStraightLine(vector<vector<int>>& a) {
        if (a.size() == 2) return true;
        for (int i=3; i<a.size();++i)
            if (!check(a[0],a[1],a[i])) return false;
        return true;
    }
};
