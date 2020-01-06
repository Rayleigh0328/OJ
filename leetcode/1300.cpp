class Solution {
    
    const int inf = (1<<28);
    
    int n;
    vector<int> s;
    vector<int> a;
    
    int get_result(int threshold){
        auto it = lower_bound(a.begin(), a.end(), threshold);
        if (it == a.end()) return s.back();
        int offset = it - a.begin();
        return s[offset] - a[offset] + threshold * (n - offset); 
    }
    
public:
    int findBestValue(vector<int>& arr, int target) {
        a = arr;
        n = a.size();
        sort(a.begin(), a.end());
        s = vector<int>(n);
        s[0] = a[0];
        for (int i=1;i<s.size();++i)
            s[i] = s[i-1] + a[i];
        
        int diff = inf, result = -1;
        int left = 0, right = target+1, mid;
        while (left < right){
            mid = left + ((right - left) >> 1);
            int tmp = get_result(mid);
            // printf("threshold %d, result %d\n", mid, tmp);
            if (abs(tmp - target) < diff){
                diff = abs(tmp-target);
                result = mid;
            }
            if (abs(tmp - target) == diff) result = min(result, mid);
            if (tmp < target) left = mid+1;
            else right = mid;
        }
        return result;
    }
};
