class Solution {
    int n;
    
    vector<int> construct_ans(int s, const vector<int>& a){
        vector<int> ans;
        for (int i=0;i<n;++i)
            if ((s & (1<<i)) > 0) ans.push_back(a[i]);
        return ans;
    }
    
public:
    vector<vector<int>> subsets(vector<int>& a) {
        n = a.size();
        vector<vector<int>> ans;
        for (int s = 0; s< (1 << n); ++s){
            ans.push_back(construct_ans(s,a));
        }
        return ans;
    }
};
