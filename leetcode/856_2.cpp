class Solution {
public:
    int scoreOfParentheses(string s) {
        int left=0, right=0, result = 0;
        s += '(';
        for (int i=0;i<s.size();++i){
            if (s[i] == '(') {
                ++left;
                if (right > 0) result += (1<<(right-1+left-1));
                right = 0;
            }
            else{
                --left;
                ++right;
            }
        }
        return result;
    }
};
