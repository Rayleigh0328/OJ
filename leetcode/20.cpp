class Solution {
public:
    bool isValid(string str) {
        stack<char> s;
        for (int i=0;i<str.length();++i)
        {
            if (str[i] == '(' || str[i] == '{' || str[i] == '[' ) s.push(str[i]);
            if (str[i] == ')')
                if (!s.empty() && s.top() == '(') s.pop();
                else return false;
            if (str[i] == '}')
                if (!s.empty() && s.top() == '{') s.pop();
                else return false;
            if (str[i] == ']')
                if (!s.empty() && s.top() == '[') s.pop();
                else return false;
        }
        return s.empty();
    }
};
