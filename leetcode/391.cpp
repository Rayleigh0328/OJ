struct Rectangle{
    int top, bottom, left, right;
    
    Rectangle(int top, int bottom, int left, int right):
        top(top),
        bottom(bottom),
        left(left),
        right(right)
    {}
};

bool cmp_rectangle(const Rectangle& x, const Rectangle &y){
    return x.left < y.left;
}

struct Interval{
    int left, right;
    
    Interval(int left, int right):
        left(left),
        right(right)
    {}
};

class Solution {
    vector<Rectangle> a;
    map<int, vector<int>> height_to_add;
    map<int, vector<int>> height_to_remove;

    bool check_form_interval(const vector<int>& v){
        for (int i=1;i<v.size();++i)
            if (a[v[i-1]].right != a[v[i]].left) return false;
        return true;
    }
    
    bool construct_interval(const vector<int> &ind, vector<Interval>& result){
        result.clear();
        result.push_back(Interval(a[ind[0]].left, a[ind[0]].right));
        for (int i=1;i<ind.size();++i){
            if (result.back().right == a[ind[i]].left){
                result.back().right = a[ind[i]].right;
            }
            else if (result.back().right < a[ind[i]].left) {
                result.push_back(Interval(a[ind[i]].left, a[ind[i]].right));
            }
            else {
                return false;
            }
        }
        return true;
    }
    
    bool check_same_interval(const vector<int>& u, const vector<int>& v){
        vector<Interval> u_int;
        vector<Interval> v_int;
        if (!construct_interval(u, u_int)) return false;
        if (!construct_interval(v, v_int)) return false;
        
        if (u_int.size() != v_int.size()) return false;
        for (int i=0;i<u_int.size();++i)
            if (u_int[i].left != v_int[i].left
                || u_int[i].right != v_int[i].right)
                return false;
        return true;
    }
    
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        
        // build the array of rectangles, rectangles are sorted by left position
        for (const auto &e : rectangles)
            a.push_back(Rectangle(e[2],e[0],e[1],e[3]));
        sort(a.begin(),a.end(),cmp_rectangle);
        
        // log events
        for (int i=0;i<a.size();++i){
            height_to_add[a[i].bottom].push_back(i);
            height_to_remove[a[i].top].push_back(i);
        }
        
        // check first scan position
        if (!check_form_interval(height_to_add.begin()->second)) return false;
        height_to_add.erase(height_to_add.begin());
        
        // check following height
        while (!height_to_add.empty()){
            int height1 = height_to_add.begin()->first;
            int height2 = height_to_remove.begin()->first;
            if (height1 != height2) return false;
            
            vector<int>& adds = height_to_add.begin()->second;
            vector<int>& removes = height_to_remove.begin()->second;
            if (!check_same_interval(adds, removes)) return false;
            
            height_to_add.erase(height_to_add.begin());
            height_to_remove.erase(height_to_remove.begin());
        }
        
        return true;
    }
};
