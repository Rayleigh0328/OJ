class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> stack;
        stack.push('0'-1);
        int count = 0;
        int pos = 0;
        while (pos < num.length()){
            if (num[pos] < stack.top()){
                stack.pop();
                if (++count == k) break;
            }
            else{
                stack.push(num[pos++]);
            }
        }
        while (pos != num.length()) stack.push(num[pos++]);
        while (count < k){
            stack.pop();
            ++count;
        }
        string ans;
        while (stack.size() > 1){
            ans = stack.top() + ans;
            stack.pop();
        }
        while (ans.length() > 0 && ans[0]=='0') {
            cout << "remove 0" << endl;
            ans.erase(0,1);
        }
        return (ans.length()==0?"0":ans);
    }
};
