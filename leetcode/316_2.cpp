class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> last_pos;
        for (int i=s.length()-1; i>=0; --i)
            if (last_pos.find(s[i]) == last_pos.end()) last_pos.emplace(s[i],i);
        
        unordered_set<char> in_stack;
        stack<char> stack;
        for (int i=0; i<s.length();++i){
            char ch = s[i];
            if (in_stack.find(ch) != in_stack.end()) continue;
            while (!stack.empty() && stack.top() > ch && last_pos[stack.top()] > i){
                in_stack.erase(stack.top());
                stack.pop();
                // cout << "pop" << endl;
            }
            stack.push(ch);
            // cout<< "push: " << ch << endl;
            in_stack.insert(ch);
        }
        string ans = "";
        while (!stack.empty()){
            ans = stack.top() + ans;
            stack.pop();
        }
        return ans;
    }
};
