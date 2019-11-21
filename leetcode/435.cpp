struct Interval{
    int s, e;
    
    Interval():Interval(0,0){}
    Interval(int start, int end):s(start),e(end){}
    
    bool operator<(const Interval& other){
        return e < other.e;
    }
    
};

const int inf = (1<<30);

class Solution {
    
    int find(const vector<Interval> &a, int k){
        // find right most interval with end point <= k
        int left = 0, right = a.size(), mid;
        while (left < right){
            if (left + 1 == right) return left;
            if (left + 2 == right){
                if (a[left+1].e <= k) return left+1;
                return left;
            } 
            mid = left + ((right - left) >> 1);
            if (a[mid].e <= k) left = mid;
            else right = mid;
        }
        return -1;
    }
    
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<Interval> a;
        a.push_back(Interval(-inf, -inf));
        for (const auto &e: intervals)
            a.push_back(Interval(e[0],e[1]));
        sort(a.begin(), a.end());
        
        vector<int> f(n+1);
        f[0] = 0;
        for (int i=1;i<=n;++i){
            f[i] = f[i-1] + 1;
            int pos = find(a,a[i].s);
            f[i] = min(f[i], f[pos] + (i-pos-1));
        }
        return f[n];
    }
};
