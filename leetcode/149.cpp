class Solution {
    
    bool same_point(const vector<int> &p1, const vector<int> &p2){
        return (p1[0] == p2[0] && p1[1] == p2[1]);
    }
    
    bool all_same(vector<vector<int>>& a){
        for (int i=1;i<a.size();++i)
            if (!same_point(a[0], a[i])) return false;
        return true;
    }
    
    bool same_line(const vector<int> &p0, const vector<int> &p1, const vector<int> &p2){
        long long x1 = p1[0] - p0[0];
        long long y1 = p1[1] - p0[1];
        long long x2 = p2[0] - p0[0];
        long long y2 = p2[1] - p0[1];
        return (x1*y2 - x2*y1 == 0);
    }
    
    
public:
    int maxPoints(vector<vector<int>>& a) {
        int n = a.size();
        if (n < 3) return n;
        if (all_same(a)) return n;
        int ans = 0;
        for (int i=0;i<n;++i)
            for (int j=i+1;j<n;++j){
                if (same_point(a[i],a[j])) continue;
                int current_ans=0;
                for (int k=0;k<n;++k)
                    if (same_line(a[i],a[j],a[k])) ++current_ans;
                if (current_ans > ans) ans = current_ans;
            }
        
        return ans;
    }
};
