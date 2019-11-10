class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int n = colsum.size();
        int up_left = upper;
        int dn_left = lower;
        vector<int> up(n,0);
        vector<int> dn(n,0);
        
        for (int i=0;i<n;++i)
            if (colsum[i] == 2){
                up[i] = dn[i] = 1;
                if (up_left == 0 || dn_left == 0) return {};
                --up_left;
                --dn_left;
            }
        
        for (int i=0;i<n;++i)
            if (colsum[i] == 1){
                if (up_left > 0){
                    --up_left;
                    up[i] = 1;
                }
                else if (dn_left > 0){
                    --dn_left;
                    dn[i] = 1;
                }
                else {
                    return {};
                }
            }
        
        if (up_left > 0 || dn_left > 0) return {};
        return {up, dn};
    }
};
