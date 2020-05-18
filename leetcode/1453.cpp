class Solution {
    
    typedef pair<double, double> Point;
    
    const double eps = 1e-6;
    
    bool overlap(Point &p1, Point &p2){
        return (abs(p1.first - p2.first) < eps && abs(p1.second - p2.second) < eps);
    }
    
    double dist2(Point &p1, Point p2){
        return (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second)*(p1.second - p2.second);
    }
    
    double v_length(Point &p){
        return sqrt(p.first * p.first + p.second * p.second);
    }    
    
    Point add(Point &p1, Point &p2){
        return Point(p1.first + p2.first, p1.second + p2.second);
    }
    
    Point minus(Point &p1, Point &p2){
        return Point(p1.first - p2.first, p1.second - p2.second);
    }
    
    int count(vector<Point> &a, Point &c, double r){
        int result = 0;
        for (auto &e : a)
            if (dist2(e,c) <= r*r + eps) ++result;
        return result;
    }
    
    vector<Point> get_centers(Point &p1, Point &p2, int r){
        vector<Point> result;
        double x1 = p1.first;
        double y1 = p1.second;
        double x2 = p2.first;
        double y2 = p2.second;
        Point mid = Point((x1+x2) / 2, (y1+y2)/2);
        
        Point p1p2 = Point(x2-x1, y2-y1);
        double a = v_length(p1p2)/2;
        if (a > r) return result;
        double b = sqrt(r * r - a * a);
        
        double len = v_length(p1p2);
        Point oth = Point((y1-y2)/len*b, (x2-x1)/len*b);
        
        result.push_back(add(mid, oth));
        result.push_back(minus(mid, oth));
        
        return result;
    }
    
public:
    int numPoints(vector<vector<int>>& points, int r) {
        const int n = points.size();
        vector<Point> a;
        for (auto &e : points){
            a.push_back(Point(e[0], e[1]));
        }
        
        int result = 1;
        for (auto &p1 : a)
            for (auto &p2 : a){
                if (overlap(p1,p2)) continue;
                vector<Point> centers = get_centers(p1,p2,r);
                for (auto center : centers)
                    result = max(result, count(a,center,r));
            }
        
        return result;
    }
};
