class Solution {
private:
    void solve(int left, int right, string cur_ans, vector<string> &ans)
    {
        if (left > right) return;
        if (left < 0) return;
        if (right < 0) return;
        
        if (left == 0 && right == 0) ans.push_back(cur_ans);
        solve(left-1, right, cur_ans + "(", ans);
        solve(left, right-1, cur_ans + ")", ans);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        ans.clear();
        solve(n,n,"",ans);
        return ans;
    }
};