class Solution {
    
    typedef string Slope;
    
    bool same_point(const vector<int> &p1, const vector<int> &p2){
        return (p1[0] == p2[0] && p1[1] == p2[1]);
    }
    
    int gcd(int x, int y){
        int r = x % y;
        if (r == 0) return y;
        return gcd(y,r);
    }
    
    Slope get_slope(const vector<int> &p1, const vector<int> &p2){
        int dx = p2[0]-p1[0];
        int dy = p2[1]-p1[1];
        if (dy == 0) return "inf";
        int g = gcd(dx,dy);
        return to_string(dx/g) + "|" + to_string(dy/g);
    }
    
public:
    int maxPoints(vector<vector<int>>& a) {
        int n = a.size();
        if (n < 3) return n;
        
        int ans = 0;
        for (int i=0;i<n;++i){
            int same_count = 0;
            unordered_map<Slope, int> slope_count;
            for (int j=i+1;j<n;++j){
                if (same_point(a[i],a[j])) {
                    ++same_count;
                    continue;
                }
                ++slope_count[get_slope(a[i],a[j])];
            }
            int tmp=0;
            for (auto e : slope_count)
                tmp = max(tmp, e.second);
            ans = max(ans, tmp + same_count + 1);
        }
        
        return ans;
    }
};
