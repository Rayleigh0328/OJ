
class Solution {
    public int longestValidParentheses(String s) {
        if (s == "") return 0;

        Stack<Integer> stack = new Stack<>();
        stack.push(-1);
        int ans = 0;
        for (int i=0;i<s.length();++i){
            if (s.charAt(i) == '(') {
                stack.push(i);
            }
            else {
                // )
                if (stack.size() > 1 && s.charAt(stack.peek()) == '(') {
                    // match
                    stack.pop();
                }
                else{
                    // does not match, extra )
                    ans = Math.max(ans, i-stack.peek()-1);
                    stack.push(i);
                }
            }
        }
        ans = Math.max(ans, s.length() - stack.peek() - 1);
        while (stack.size() > 1) {
            int top = stack.pop();
            ans = Math.max(ans, top - stack.peek() -1);
        }
        return ans;
    }
}

