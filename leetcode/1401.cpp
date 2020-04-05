class Solution {
    typedef pair<int,int> point;
    
    int sq_dist(const point &p1, const point& p2){
        return (p1.first - p2.first) * (p1.first - p2.first) + 
               (p1.second - p2.second) * (p1.second - p2.second);
    }
public:
    bool checkOverlap(int r, int xc, int yc, int x1, int y1, int x2, int y2) {
        point cp(xc,yc);
        
        vector<point> a;
        a.push_back(point(x1,y1));
        a.push_back(point(x1,y2));
        a.push_back(point(x2,y2));
        a.push_back(point(x2,y1));
        
        // (xc, yc) in square
        if (x1 <= xc && xc <= x2 && y1 <= yc && yc <= y2) 
            return true;
        
        // sort by distance to (xc, yc)
        sort(a.begin(), a.end(), [xc,yc](const point &p1, const point &p2){
            int d1 = (xc-p1.first) * (xc-p1.first) + (yc-p1.second) * (yc-p1.second);
            int d2 = (xc-p2.first) * (xc-p2.first) + (yc-p2.second) * (yc-p2.second);
            return d1 < d2;
        });
        
        // point in circle
        if (sq_dist(cp, a[0]) <= r*r) return true;
        
        printf("a[0]: (%d, %d)\n", a[0].first, a[0].second);
        printf("a[1]: (%d, %d)\n", a[1].first, a[1].second);
        printf("a[2]: (%d, %d)\n", a[2].first, a[2].second);
        printf("a[3]: (%d, %d)\n", a[3].first, a[3].second);
        
        // a[0], a[1]
        if (a[0].first == a[1].first){
            if (abs(cp.first-a[0].first)<=r && 
                    min(a[0].second, a[1].second) <= cp.second && 
                    cp.second <= max(a[0].second, a[1].second)) return true;
        }
        if (a[0].second == a[1].second){
            if (abs(cp.second-a[0].second)<=r && 
                    min(a[0].first, a[1].first) <= cp.first && 
                    cp.first <= max(a[0].first, a[1].first)) return true;
        }
        
        // a[0], a[2]
        if (a[0].first == a[2].first){
            if (abs(cp.first-a[0].first)<=r && 
                    min(a[0].second, a[2].second) <= cp.second && 
                    cp.second <= max(a[0].second, a[2].second)) return true;
        }
        if (a[0].second == a[2].second){
            if (abs(cp.second-a[0].second)<=r && 
                    min(a[0].first, a[2].first) <= cp.first && 
                    cp.first <= max(a[0].first, a[2].first)) return true;
        }
        
        return false;
    }
};
