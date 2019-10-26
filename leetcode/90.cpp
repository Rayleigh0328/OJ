class Solution {
    
    void solve(const vector<int> &a, int pos, vector<int> &current, vector<vector<int>> &result){
        if (pos == a.size()){
            result.push_back(current);
            return;
        }
        
        int next = pos + 1;
        while (next < a.size() && a[next] == a[pos]) ++next;
        
        for (int i=0;i<=next-pos;++i){
            for (int j=0;j<i;++j) current.push_back(a[pos]);
            solve(a,next,current,result);
            for (int j=0;j<i;++j) current.pop_back();
        }
        
    }
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& a) {
        sort(a.begin(), a.end());
        vector<vector<int>> result;
        vector<int> current;
        solve(a, 0, current, result);
        return result;
    }
};
