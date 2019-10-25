class Solution {
    
    void solve(const vector<int>& a, int pos, int target, vector<int>& current, vector<vector<int>>& result){
        // printf("solve pos %d, target %d\n",pos, target);
        if (target == 0) {
            result.push_back(current);
            return;
        }
        if (target < 0 || pos <0) return;
        current.push_back(a[pos]);
        solve(a,pos,target-a[pos], current, result);
        current.pop_back();
        
        solve(a,pos-1, target, current, result);
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& a, int target) {
        sort(a.begin(), a.end());
        vector<vector<int>> result;
        vector<int> current;
        solve(a,a.size()-1,target, current, result);
        return result;
    }
};
