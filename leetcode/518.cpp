class Solution {

    vector<vector<int>> f;
    vector<int> a;
    
    int solve(int k, int index){
        if (index >= a.size()) return (k == 0?1:0);
        if (f[k][index] != -1) return f[k][index];
        if (k == 0) return (f[k][index] = 1);
        
        
        f[k][index] = 0;
        for (int i=0; i<= k / a[index]; ++i)
            f[k][index] += solve(k-i*a[index], index+1);
        return f[k][index];
    }
    
public:
    int change(int amount, vector<int>& coins) {
        a = coins;
        sort(a.begin(), a.end(), greater<int>());
        f = vector<vector<int>>(amount+1, vector<int>(a.size(), -1));
        return solve(amount, 0);
    }
};
