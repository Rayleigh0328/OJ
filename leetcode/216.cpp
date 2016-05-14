class Solution {
private:
    vector<vector<int>> ans;
    void solve(int num_cnt, int digit, int tar, vector<int> cur)
    {
        if (num_cnt == 0 && tar == 0)
            if (unique(cur)) ans.push_back(cur);
            
        if (num_cnt < 0) return;
        if (tar < 0) return;
        if (digit < 1) return;
        
        solve(num_cnt, digit - 1, tar, cur);
        cur.push_back(digit);
        solve(num_cnt-1, digit - 1, tar-digit, cur);
    }
    
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
public:
    vector<vector<int>> combinationSum3(int k, int n) 
    {
        ans.clear();
        solve(k,9,n,vector<int>());
        for (int i=0;i<ans.size();++i)
            reverse(ans[i].begin(), ans[i].end());
        return ans;
    }
};