class Solution {
public:
    string reverseParentheses(string s) {
        vector<char> v;
        for (int i=0;i<s.length();++i){
            if (s[i]==')'){
                vector<char> tmp;
                while (v[v.size()-1] != '(') {
                    tmp.push_back(v[v.size() - 1]);
                    v.pop_back();
                }
                v.pop_back();
                for (char ch : tmp) v.push_back(ch);
            }
            else{
                v.push_back(s[i]);
            }
        }
        string ans;
        for (char ch : v) ans += ch;
        return ans;
    }
};
