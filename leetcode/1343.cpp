class Solution {
public:
    int numOfSubarrays(vector<int>& a, int k, int threshold) {
        int sum = 0;
        int result = 0;
        for (int i=0;i<k;++i) sum += a[i];
        if (sum >= threshold * k) ++result;
        for (int i=k;i<a.size();++i){
            sum -= a[i-k];
            sum += a[i];
            if (sum >= threshold * k) ++result;
        }
        return result;
    }
};
