class Solution {
private:
    vector<vector<int>> ans;
    
    void solve(int left, int right, int num, vector<int> cur)
    {
        //cout << left << " " << right << " " << num << endl;
        for (int i=left; i<=right; ++i)
            if (right - i + 1 < num) break;
            else
            {
                cur.push_back(i);
                if (num == 1)
                    ans.push_back(cur);
                else
                    solve(i+1, right, num-1, cur);
                cur.pop_back();
            }
    }
public:
    vector<vector<int>> combine(int n, int k) 
    {
        ans.clear();
        solve(1,n,k,vector<int>());
        return ans;
    }
};