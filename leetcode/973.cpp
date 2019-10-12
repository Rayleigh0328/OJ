struct point{
    int x, y;
    
    point(int xx, int yy):x(xx), y(yy){}
};

int sq_dist(const point &p){
    return p.x * p.x + p.y * p.y;
}

bool cmp(const point &p1, const point &p2){
    return sq_dist(p1) < sq_dist(p2); 
}

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<point> a;
        for (int i=0;i<points.size();++i)
            a.push_back(point(points[i][0], points[i][1]));
        sort(a.begin(), a.end(), cmp);
        vector<vector<int>> ans;
        for (int i=0; i<K; ++i){
            vector<int> row{a[i].x, a[i].y};
            ans.push_back(row);
        }
        return ans;
    }
};
