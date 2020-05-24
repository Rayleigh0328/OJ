class Solution {
public:
    int scoreOfParentheses(string s) {
        vector<string> a;
        for (int i=0;i<s.size();++i){
            char ch = s[i];
            if (ch == '('){
                a.push_back("(");
            }
            else {
                if (a.back() == "(") {
                    a.pop_back(); 
                    a.push_back("1");
                    continue;
                }
                while (a.size() > 1 && a.back() != "(" && a[a.size()-2] != "(") {
                    int tmp = stoi(a.back());
                    a.pop_back();
                    tmp += stoi(a.back());
                    a.pop_back();
                    a.push_back(to_string(tmp));
                }
                int x = stoi(a.back());
                a.pop_back();
                a.pop_back();
                a.push_back(to_string(x * 2));
            }
        }
        
        int result = 0;
        while (!a.empty()) {
            result += stoi(a.back());
            a.pop_back();
        }
        return result;
    }
};
