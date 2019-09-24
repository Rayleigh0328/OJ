class Solution {
    
    vector<string> split(string st, char ch){
        vector<string> result;
        if (st.length() == 0) return result;
        int left = 0;
        int right = 0;
        while (true){
            while (left < st.length() && st[left] == ch) ++left;
            if (left == st.length()) return result;
            right = left + 1;
            while (right < st.length() && st[right] != ch) ++right;
            result.push_back(st.substr(left, right-left));
            left = right;
        }
        return result;
    }
    
public:
    string simplifyPath(string path) {
        vector<string> folders = split(path, '/');
        //for (auto s : folders) cout << s << " "; cout << endl;
        vector<string> stack;
        for (auto s : folders){
            if (s == ".") continue;
            if (s == "..") {
                if  (!stack.empty()) stack.pop_back();
            }
            else stack.push_back(s);
        }
        if (stack.empty()) return "/";
        string ans;
        for (auto s : stack)
            ans += ("/" + s);
        return ans;
    }
};
