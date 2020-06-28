class Solution {
    
    typedef pair<int, int> Point;
    
    Point move(Point p, char d){
        if (d == 'N')
            return Point(p.first+1, p.second);
        else if (d == 'S')
            return Point(p.first-1, p.second);
        else if (d == 'E')
            return Point(p.first, p.second + 1);
        else 
            return Point(p.first, p.second - 1);
    }
    
public:
    bool isPathCrossing(string path) {
        set<Point> s;
        Point cur = Point(0,0);
        s.emplace(cur);
        for (int i=0;i<path.size();++i){
            char d = path[i];
            cur = move(cur, d);
            if (s.find(cur) != s.end()) return true;
            s.emplace(cur);
        }
        return false;
    }
};
