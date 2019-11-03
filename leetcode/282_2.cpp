class Solution {

    string s;
    int n;
    int goal;
    vector<int> state; 
    // state[i] means what to put after s[i]
    // 0 => nothing, do not split
    // 1 => +
    // 2 => -
    // 3 => *
    vector<string> result;
    
    bool is_digit(char ch){
        return '0' <= ch && ch <= '9';
    }
    
    long long get_operand(const string & cand, int pos, int& next_pos){
        long long result=0;
        // leading zero
        if (cand[pos] == '0'){
            if (pos+1 < cand.length() && is_digit(cand[pos+1])) return -1;
            next_pos = pos+1;
            return 0;
        }
        
        while (pos < cand.length() && is_digit(cand[pos])){
            result = result * 10 + cand[pos++]-'0';
        }
        
        next_pos = pos;
        return result;
    }
    
    void check_candidate(const string &cand){
        // cout << "candidate: " << cand << endl;
        int pos, next_pos;
        long long val = get_operand(cand, 0, pos);
        long long prev = val;
        long long operand;
        if (val == -1) return;
        while (pos < cand.length()){
            operand = get_operand(cand, pos+1, next_pos);
            if (operand == -1) return;
            if (cand[pos] == '+'){
                val = val + operand;
                prev = operand;
            }
            else if (cand[pos] == '-'){
                val = val - operand;
                prev = -operand;
            }
            else {
                val = val - prev + prev * operand;
                prev = prev * operand;
            }
            pos = next_pos;
        }
        if (val == goal)
            result.push_back(cand);
    }
    
    void check_answer(){
        string candidate;
        for (int i=0;i<=n-2;++i){
            candidate += s[i];
            if (state[i] == 1) candidate += '+';
            else if (state[i] == 2) candidate += '-';
            else if (state[i] == 3) candidate += '*';
        }
        candidate += s[n-1];
        check_candidate(candidate);
    }
    
    void solve(int pos){
        if (pos == n-1){
            check_answer();
            return;
        }
        for (int i=0;i<4;++i){
            state[pos] = i;
            solve(pos+1);
        }
    }
    
public:
    vector<string> addOperators(string num, int target) {
        s = num;
        n = s.length();
        goal = target;
        if (n == 0) return {};
        if (n == 1){
            if (stoi(s) == target) return {s};
            else return {};
        }
        
        state=vector<int>(n-1,-1);
        solve(0);
        return result;
    }
};
