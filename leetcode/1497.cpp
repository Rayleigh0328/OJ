class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> b(k,0);
        int r;
        for (auto x : arr){
            r = x % k;
            if (r < 0) r += k;
            ++b[r];
            // printf("%d ", r);
        }
        // printf("\n");
        // for (int i=0; i<k; ++i) printf("%d ", b[i]); printf("\n");
        if (b[0] % 2 != 0) return false;
        
        if (k % 2 == 0){
            for (int i=1;i<k/2;++i)
                if (b[i] != b[k-i]) return false;
            return (b[k/2] % 2 == 0);
        }
        else {
            for (int i=1;i<=k/2;++i){
                if (b[i] != b[k-i]) return false;
            }
            return true;
        }
    }
};
