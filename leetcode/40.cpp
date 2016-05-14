class Solution {
private:
    vector<vector<int>> ans;
    
    bool unique(vector<int>& cur_vect)
    {
        for (int i=0;i<ans.size();++i)
        {
            if (ans[i].size() != cur_vect.size()) continue;
            bool pass = false;
            for (int j=0;j<ans[i].size();++j)
                if (ans[i][j] != cur_vect[j]) pass = true;
            if (!pass) return false;
        }
        return true;
    }
    
    void solve(int cur_target, vector<int>& cand, int ind, vector<int> cur_vect)
    {
        // cout << cur_target << " " << ind << "\t\t";
        // cout << "vect: ";
        // for (int i=0;i<cur_vect.size();++i)
        //     cout << cur_vect[i] << " ";
        // cout << endl;
        
        if (cur_target == 0)
        {
            if (unique(cur_vect))
                ans.push_back(cur_vect);
            return;
        }
        
        if (ind < 0) return;
        
        // for (int i=0;i*cand[ind] <= cur_target;++i)
        // {
        //     solve(cur_target - i*cand[ind], cand, ind - 1, cur_vect);
        //     cur_vect.push_back(cand[ind]);
        // }
        
        solve(cur_target, cand, ind-1, cur_vect);
        if (cur_target - cand[ind] >=0)
        {
            cur_vect.push_back(cand[ind]);
            solve(cur_target-cand[ind], cand, ind-1, cur_vect);
        }
    }
    
public:
    vector<vector<int>> combinationSum2(vector<int>& cand, int target) 
    {
        ans.clear();
        sort(cand.rbegin(), cand.rend());
        solve(target, cand, cand.size()-1, vector<int>());
        
        return ans;
    }
};