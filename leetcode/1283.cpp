class Solution {
    const int inf = (1<<21);
    const double eps = 1e-8;
    
    bool check(const vector<int>&a, int divisor, int threshold){
        int sum = 0;
        for (int x : a)
            sum += ceil(static_cast<double>(x) / divisor - eps);
        return sum <= threshold;
    }
    
public:
    int smallestDivisor(vector<int>& a, int threshold) {
        int left = 1, right = inf, mid;
        while (left < right){
            if (left + 1 == right) return left;
            if (left + 2 == right){
                if (check(a, left, threshold)) return left;
                return left+1;
            }
            mid = left + ((right - left) >> 1);
            if (check(a, mid, threshold)) right = mid + 1;
            else left = mid + 1;
        }
        return -1;
    }
};
