struct Rectangle{
    int top, bottom, left, right;
    
    Rectangle(int top, int bottom, int left, int right):
        top(top),
        bottom(bottom),
        left(left),
        right(right)
    {}
};

typedef pair<int, int> Point;


class Solution {
    vector<Rectangle> a;
    const int inf = (1<<30);
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        
        // build the array of rectangles, rectangles are sorted by left position
        for (const auto &e : rectangles)
            a.push_back(Rectangle(e[3],e[1],e[0],e[2]));
        
        int left = inf, right = -inf, top = -inf, bottom = inf;
        for (const auto &r : a){
            if (r.top > top) top = r.top;
            if (r.bottom < bottom) bottom = r.bottom;
            if (r.right > right) right = r.right;
            if (r.left < left) left = r.left;
        }
        
        // check area
        int total_area = (right - left) * (top - bottom);
        for (const auto &rect : a){
            total_area -= (rect.top-rect.bottom)*(rect.right-rect.left);
        }
        if (total_area != 0) return false;
        // printf("area check is good\n");
        // printf("left: %d, right: %d, top: %d, bottom: %d\n", left, right, top, bottom);
        // check point
        map<Point, int> point_to_count; 
        ++point_to_count[Point(left, bottom)];
        ++point_to_count[Point(right, bottom)];
        ++point_to_count[Point(left, top)];
        ++point_to_count[Point(right, top)];
        for (const auto& rect : a){
            ++point_to_count[Point(rect.left, rect.bottom)];
            ++point_to_count[Point(rect.right, rect.bottom)];
            ++point_to_count[Point(rect.left, rect.top)];
            ++point_to_count[Point(rect.right, rect.top)];
        }
        
        for (auto &e : point_to_count){
            // printf("(%d,%d)->%d\n", e.first.first, e.first.second, e.second);
            if (e.second != 2 && e.second != 4) return false;
        }
        return true;
    }
};
