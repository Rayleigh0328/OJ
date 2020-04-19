class Solution {
    
    string solve(string &a, string &b){
        if (a.size() > b.size() + 1) return "";
        int  p = 0;
        string result;
        for (; p < b.size(); ++p){
            result.push_back(a[p]);
            result.push_back(b[p]);
        }
        if (p < a.size()) result.push_back(a.back());
        return result;
    }
    
public:
    string reformat(string s) {
        string chars, digits;
        char ch;
        for (int i=0;i<s.size();++i){
            ch = s[i];
            if ('a' <= ch && ch <='z') chars.push_back(ch);
            else digits.push_back(ch);
        }
        
        if (chars.size() > digits.size()) return solve(chars, digits);
        else return solve(digits, chars);
    }
};
