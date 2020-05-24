
class Solution {
    
    typedef complex<double> P;
    typedef complex<double> V;
    
    const double eps = 1e-6;
    
    double cross_product(const V &u, const V &v){
        return real(u)*imag(v) - real(v)*imag(u);
    }

    double dot_product(const V &u, const V &v){
        return real(u)*real(v) + imag(u)*imag(v);
    }
    
    bool same_line(const P &p1, const P &p2, const P &p3){
        V u = p2-p1;
        V v = p3-p1;
        return abs(cross_product(u,v)) < eps;
    }
    
    // get convex hull starting from the lowest then leftmost point
    // points on the convex hull will be in counter-clockwise order
    // start point will appear again at the end of the vector
    // if keep_on_bounday is set to true, then all points that lies on the hull
    // will be added, otherwise, only endpoint of the segment.
    vector<P> get_convex_hull(const vector<P> &input, bool keep_on_boundary){

        vector<P> a(input);
        
        //after this step, a[0] will be the lowerest then leftmost point
        for (int i=1;i<a.size();++i)
            if (imag(a[i]) < imag(a[0]) || (imag(a[i]) == imag(a[0]) && real(a[i]) < real(a[0])))
                swap(a[0], a[i]);

        P s = a[0];
        
        // sort points in a except for a[0] first by polar angle of sp
        // then by norm of sp
        sort(a.begin() + 1, a.end(), [this,s](const P &p1, const P &p2){
            V sp1 = p1-s;
            V sp2 = p2-s;
            double tmp = cross_product(sp1,sp2);
            if (tmp > eps) return true;
            if (tmp < -eps) return false;
            return norm(sp1) < norm(sp2);
        });
        
        // add s to the end to close the hull
        a.push_back(s);
        
        vector<P> result;
        for (int i=0;i<a.size();++i){
            if (result.size() < 2) {
                result.push_back(a[i]);
                continue;
            }
        
            // monotonic stack that maintains the turn-left property
            V u = result.back() - result[result.size()-2];
            V v = a[i] - result.back();
            double tmp = cross_product(u,v);
            while (tmp < -eps || (!keep_on_boundary && abs(tmp) < eps)) {
                result.pop_back();
                
                if (result.size() == 1) break;
                u = result.back() - result[result.size()-2];
                v = a[i] - result.back();
                tmp = cross_product(u,v);
            }
            
            result.push_back(a[i]);
        }

        // in case of get all points on boundary
        // the points on the last segment will be missing
        // add them back into the hull
        if (keep_on_boundary && !same_line(s, result[result.size()-2], result[1])){
            result.pop_back();
            P t = result.back();
            result.pop_back();
            for (int i=a.size()-2;i>=0;--i)
                if (same_line(s,t,a[i])) {
                    result.push_back(a[i]);
                }
                else break;
            result.push_back(s);
        }
        
        return result;
    }
    
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& points) {
        if (points.size() < 4) return points;
        // convert vector<vector<int>> to vector<P>
        vector<P> input;
        for (auto &p : points){
            input.push_back(P(p[0], p[1]));
        }
        
        vector<P> tmp = get_convex_hull(input, true);
        
        // convert to output format
        vector<vector<int>> result;
        for (int i=1;i<tmp.size();++i){
            P p = tmp[i];
            result.push_back({(int)round(real(p)),(int)round(imag(p))});
        }
        return result;
    }
};
