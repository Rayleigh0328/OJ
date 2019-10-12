
struct car{
    int number;
    double arrive_time;
    int start_dist;
    
    car(int n, double at, int sd):
        number(n),
        arrive_time(at),
        start_dist(sd)
    {}
};

const int eps = 1e-8;

bool cmp(const car &x, const car &y){
    return x.start_dist < y.start_dist;
}

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {        
        int n = position.size();
        if (n == 0) return 0;
        
        vector<car> a;
        for (int i=0;i<n;++i)
            a.push_back(car(i, (0.0 + target-position[i])/speed[i], target-position[i]));
        
        sort(a.begin(), a.end(), cmp);
        
        int ans=1;
        double max_time = a[0].arrive_time;
        for (int i=1;i<a.size();++i)
            if (a[i].arrive_time > max_time + eps){
                ++ans;
                max_time = a[i].arrive_time;
            }
        
        return ans;
    }
};
