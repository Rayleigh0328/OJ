class Solution {
    vector<int> a;
    vector<int> f;
    
    int solve(int target){
        if (target == 0) return 1;
        if (f[target] != -1) return f[target];
        
        int ans = 0;
        for (int x : a)
            if (target - x >=0)
                ans += solve(target - x);
        return f[target] = ans;
    }
    
public:
    int combinationSum4(vector<int>& nums, int target) {
        a = nums;
        f = vector<int> (target + 1, -1);
        return solve(target);
    }
};
