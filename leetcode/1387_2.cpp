class Solution {

    int solve(int k, vector<int> &f){
        if (f[k] != -1) return f[k];
        if (k & 1)
            return f[k] = 1 + solve(3*k + 1, f);
        else 
            return f[k] = 1 + solve(k / 2, f);
    }
    
public:
    int getKth(int lo, int hi, int k) {
        
        vector<int> weight(300000,-1);
        weight[0] = 0;
        weight[1] = 1;
        for (int i=1;i<=1000;++i) solve(i, weight);
        
        vector<int> result;
        for (int i=lo;i<=hi;++i)
            result.push_back(i);
        sort(result.begin(), result.end(), [&weight](const int &x, const int &y){
            if (weight[x] < weight[y]) return true;
            if (weight[x] > weight[y]) return false;
            return x < y;
        });
        return result[k-1];
    }
};
