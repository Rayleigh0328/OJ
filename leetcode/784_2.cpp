class Solution {
    string original;
    
    char to_upper(char ch){
        if ( 'a' <= ch && ch <='z' ) return ch-'a'+'A';
        return ch;
    }

    char to_lower(char ch){
        if ( 'A' <= ch && ch <='Z' ) return ch-'A'+'a';
        return ch;
    }
    
    void solve(int pos, string current, vector<string> &ans){
        if (pos == original.length()) {
            ans.push_back(current);
            return;
        }
        
        if ('0' <= original[pos] && original[pos] <= '9')
            solve(pos+1, current + original[pos], ans);
        else {
            solve(pos+1, current + to_upper(original[pos]), ans);
            solve(pos+1, current + to_lower(original[pos]), ans);
        }
    }
    
public:
    vector<string> letterCasePermutation(string st) {
        original = st;
        vector<string> ans;
        solve(0,"",ans);
        return ans;
    }
};
