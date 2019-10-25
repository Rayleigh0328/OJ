class Solution {
    
    void solve(const vector<int>& a, int pos, int target, vector<int>& current, vector<vector<int>>& result){
        if (target == 0){
            result.push_back(current);
            return;
        }
        if (target < 0 || pos >= a.size()) return;
        
        int next = pos;
        while (next < a.size() && a[next] == a[pos]) ++next;
        for (int i=0;i<=next-pos;++i){
            for (int j=1;j<=i;++j) current.push_back(a[pos]);
            solve(a,next,target - i * a[pos], current, result);
            for (int j=1;j<=i;++j) current.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum2(vector<int>& a, int target) {
        sort(a.begin(), a.end(), greater<int>());
        vector<vector<int>> result;
        vector<int> current;
        solve(a,0,target,current,result);
        return result;
    }
};
