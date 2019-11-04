class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        unordered_set<int> bad_pos;
        char ch;
        for (int i=0;i<s.length();++i){
            ch = s[i];
            if (ch != '(' && ch != ')') continue;
            if (ch == '(') st.push(i);
            if (ch == ')'){
                if (st.empty()) bad_pos.emplace(i);
                else st.pop();
            }
        }
        while (!st.empty()){
            bad_pos.emplace(st.top());
            st.pop();
        }
        string ans;
        for (int i=0;i<s.length();++i)
            if (bad_pos.find(i) == bad_pos.end())
                ans += s[i];
        return ans;
    }
};
