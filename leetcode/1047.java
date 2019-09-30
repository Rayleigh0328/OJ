class Solution {
    public String removeDuplicates(String st) {
        Stack<Character> stack = new Stack();
        for (int i=0; i<st.length();++i){
            if (!stack.isEmpty() && stack.peek().equals(st.charAt(i))) stack.pop();
            else stack.push(st.charAt(i));
        }
        StringBuilder sb = new StringBuilder();
        while (!stack.empty()){
            sb.append(stack.peek());
            stack.pop();
        }
        return sb.reverse().toString();
    }
}
