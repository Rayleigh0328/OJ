class Solution {
    const int mode = 1000000007;
public:
    int numSubseq(vector<int>& a, int target) {
        const int n = a.size();
        sort(a.begin(), a.end());
        
        int result = 0;
        // subseq of length 1
        for (auto x : a) if (2*x <= target) ++result;
        // printf("%d\n", result);
        
        // subseq of length >= 2
        vector<int> power(n);
        power[0] = 1;
        for (int i=1;i<n;++i) power[i] = (power[i-1] * 2) % mode;
        
        int p1 = 0, p2 = n-1;
        while (p1 < p2){
            while (a[p1] + a[p2] > target) --p2;
            if (p2-p1-1 >= 0)
                result = (result + power[p2-p1] - 1) % mode;
            // printf("p1: %d, p2: %d, result: %d\n", p1, p2, result);
            ++p1;
        }
        
        return result;
    }
};
