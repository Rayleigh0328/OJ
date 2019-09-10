class Solution {
public:
    vector<int> constructArray(int n, int k) {
        if (k >= n) return *(new vector<int>());
        vector<int> result(n,0); 
        if (k == 1) {
            for (int i=1; i<=n;++i) result[i-1]=i;
            return result;
        }
        int rev_count = (k+1)/2;
        int used=n;
        for (int i=0; i<rev_count;++i) result[i*2] = used--; 
        for (int i=n-1;i>=0;--i) if (result[i] == 0) result[i] = used--;
        for (auto x : result) cout << x << " "; cout << endl;
        if (k == n-1) return result;
        if (k % 2 == 1) {
            int tmp = result[0];
            result[0] = result[1];
            result[1] = tmp;
        }
        return result;
    }
};
