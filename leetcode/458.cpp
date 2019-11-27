class Solution {
    
    const double eps = 1e-8;
    
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int n = minutesToTest / minutesToDie + 1;
        return ceil(log(buckets) / log(n) - eps);
    }
};
