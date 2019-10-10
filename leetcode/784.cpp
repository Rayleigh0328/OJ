class Solution {
    
    char to_upper(char ch){
        if ( 'a' <= ch && ch <='z' ) return ch-'a'+'A';
        return ch;
    }
    
    char to_lower(char ch){
        if ( 'A' <= ch && ch <='Z' ) return ch-'A'+'a';
        return ch;
    }
    
    string construct(int state, const vector<int> char_pos, const string &st){
        string result = st;
        for (int i=0;i<char_pos.size();++i)
            if (state & (1<<i)){
                result[char_pos[i]] = to_upper(result[char_pos[i]]);
            }
            else {
                result[char_pos[i]] = to_lower(result[char_pos[i]]);
            }
        return result;
    }
public:
    vector<string> letterCasePermutation(string st) {
        vector<int> char_pos;
        for (int i=0; i<st.length(); ++i)
            if ('0'<= st[i] && st[i]<='9') {}
            else {
                char_pos.push_back(i);
            }
        
        // special case no char
        if (char_pos.empty()) return vector<string>{st};
        
        vector<string> ans;
        for (int i=0; i<(1<<char_pos.size()); ++i)
            ans.push_back(construct(i, char_pos, st));
        return ans;
    }
};
