class Solution {
    map<int,int> match_bracket;
    string st;
    
    string solve(int s, int t){
        if (s == t) return "";
        if (isdigit(st[s])) {
            // parse time of repetition
            int pos = s;
            int repeat = 0;
            while (isdigit(st[pos])) {
                repeat = repeat * 10 + st[pos] - '0';
                ++pos;
            }
            int end_pos = match_bracket[pos];
            string inside_string = solve(pos+1, end_pos);
            string prefix="";
            for (int i=0;i<repeat;++i) prefix += inside_string;
            return prefix + solve(end_pos + 1, t);
        }
        else{
            // start with char
            return st[s] + solve(s+1, t);
        }
    }
    
public:
    string decodeString(string input_string) {
        st = input_string;
        // find match bracket for each [
        // store in a map that from [ pos to ] pos
        match_bracket.clear();
        stack<int> stack;
        for (int i=0; i<st.length();++i)
            if (st[i]=='[') stack.push(i);
            else if (st[i]==']'){
                match_bracket.emplace(stack.top(),i);
                stack.pop();
            }
        // solve the problem recursively
        return solve(0, st.length());
    }
};
