class Solution {
    
    const double eps = 1e-6;
    
    bool stronger(int x, int y, double m){
        // printf("%d %d %d\n", x, y, m);
        if (abs(x - m) - abs(y - m) > eps) return true;
        if (abs(x - m) - abs(y - m) < -eps) return false;
        return x > y;
    }
    
public:
    vector<int> getStrongest(vector<int>& a, int k) {
        const int n = a.size();
        sort(a.begin(), a.end());
        // double median = ((n&1) ? a[n/2] : 0.5*(a[n/2]+a[n/2 - 1]));
        // printf("median: %lf\n", median);
        int median = a[(n-1)/2];
        
        vector<int> result;
        int left = 0, right = n-1;
        while (result.size() < k ){
            if (stronger(a[left], a[right], median)) result.push_back(a[left++]);
            else result.push_back(a[right--]);
        }
        
        return result;
    }
};
