class Solution {
private:
    vector<vector<int>> ans;
    
    void solve(int cur_target, vector<int>& cand, int ind, vector<int> cur_vect)
    {
        //cout << cur_target << " " << ind << endl;
        
        if (cur_target == 0)
        {
            ans.push_back(cur_vect);
            return;
        }
        
        if (ind < 0) return;
        
        for (int i=0;i*cand[ind] <= cur_target;++i)
        {
            solve(cur_target - i*cand[ind], cand, ind - 1, cur_vect);
            cur_vect.push_back(cand[ind]);
        }
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& cand, int target) 
    {
        ans.clear();
        sort(cand.rbegin(), cand.rend());
        solve(target, cand, cand.size()-1, vector<int>());
        
        return ans;
    }
};