class Solution {
    const int inf = (1<<28);
public:
    double average(vector<int>& a) {
        double sum = 0;
        int mx = -inf, mn = inf;
        for (auto x : a){
            sum += x;
            mx = max(mx, x);
            mn = min(mn, x);
        }
        
        return (sum - mx - mn) / (a.size() - 2);
    }
};
