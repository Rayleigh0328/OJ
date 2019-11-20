typedef pair<int,int> Point;

struct point_hash{
    size_t operator()(const Point &p) const{
        return p.first * 40001 + p.second;
    }
};

class Solution {
    
    const int inf = (1<<30);
    
    bool perpendicular(const Point &p0, const Point &p1, const Point &p2){
        Point v1(p1.first - p0.first, p1.second - p0.second);
        Point v2(p2.first - p0.first, p2.second - p0.second);
        return (v1.first * v2.first + v1.second * v2.second == 0);
    }
    
    int area(const Point &p0, const Point &p1, const Point &p2){
        Point v1(p1.first - p0.first, p1.second - p0.second);
        Point v2(p2.first - p0.first, p2.second - p0.second);
        return abs(v1.first * v2.second - v1.second * v2.first);
    }
    
    Point mirror(const Point &p0, const Point &p1, const Point &p2){
        return Point(p1.first + p2.first - p0.first, p1.second + p2.second - p0.second);
    }
    
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        
        vector<Point> a;
        unordered_set<Point, point_hash> point_set;
        for (const auto &e : points){
            Point p(e[0], e[1]);
            a.push_back(p);
            point_set.emplace(p);
        }
        
        if (a.size() < 4) return 0;

        int n = a.size();
        int ans = inf;
        for (int i=0;i<n;++i)
            for (int j=i+1;j<n;++j)
                for (int k=j+1;k<n;++k){
                    if (!perpendicular(a[i],a[j],a[k])) continue;
                    if (point_set.find(mirror(a[i],a[j],a[k])) == point_set.end()) continue;
                    if (area(a[i],a[j],a[k]) == 0) continue;
                    ans = min(ans, area(a[i],a[j],a[k]));
                }

        return (ans==inf?0:ans);
    }
    
};
