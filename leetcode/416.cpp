class Solution {
    
    bool solve(const vector<int>& a, int target){
        vector<bool> f(target + 1, false);
        f[0] = true;
        for (int i=0;i<a.size();++i)
            for (int j=target; j>=0;--j)
                if (f[j] && j+a[i] <= target) f[j+a[i]] = true;
        return f[target];
    }
    
public:
    bool canPartition(vector<int>& a) {
        int sum = 0;
        for (auto x : a) sum += x;
        if (sum & 1) return false;
        int target = sum / 2;
        return solve(a, target);
    }
};
