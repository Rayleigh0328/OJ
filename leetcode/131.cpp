class Solution {
    
    bool is_palindrome(const string& s, int start, int end){
        for (int i=0;i<((end-start)>>1);++i)
            if (s[start+i] != s[end-1-i]) return false;
        return true;
    }
    
    void solve(const string& s, int pos, vector<string>& state, vector<vector<string>>& result){
        if (pos == s.length()){
            result.push_back(state);
            return;
        }
        
        for (int next = pos+1;next<=s.length();++next){
            if (is_palindrome(s,pos,next)){
                state.push_back(s.substr(pos,next-pos));
                solve(s,next,state,result);
                state.pop_back();
            }
        }
    }
    
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> state;
        solve(s,0,state,result);
        return result;
    }
};
