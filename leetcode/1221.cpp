class Solution {
public:
    int balancedStringSplit(string s) {
        if (s.empty()) return 0;
        stack<char> st;
        st.push(s[0]);
        int ans = 0;
        for (int i=1;i<s.length();++i)
            if (st.empty() || st.top() == s[i]) st.push(s[i]);
            else {
                st.pop();
                if (st.empty()) ++ans;
            }
        return ans;
    }
};


