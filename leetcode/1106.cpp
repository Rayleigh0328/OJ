class Solution {

    map<int,int> close_pos;
    
    void bracket_match(const string &expr){
        stack<int> st;
        for (int pos = 0; pos < expr.length(); ++pos){
            if (expr[pos] == '(') st.push(pos);
            else if (expr[pos] == ')') {
                close_pos.emplace(st.top(), pos);
                st.pop();
            }
        }
    }
    
    int find_comma(const string &st, int left, int right){
        int ans = left;
        while (ans < right){
            if (st[ans] == ',') return ans;
            if (st[ans] == '(') ans = close_pos[ans];
            ++ans;
        }
        return ans;
    }
    
    bool solve(const string &expr, int left, int right){
        // printf("operator for %d to %d is %c\n", left, right, expr[left]);
        if (left + 1 == right){ 
            if (expr[left] == 't') return true;
            return false;
        }
        
        if (expr[left] == '!'){
            return !solve(expr, left+2, right - 1);
        }
        bool result;
        if (expr[left] == '&') {
            int p1, p2;
            result = true;
            p1 = left + 2;
            while (true){
                p2 = find_comma(expr, p1, right-1);
                result = result && solve(expr, p1, p2);
                if (p2 == right-1) break;
                p1 = p2 + 1;
            }
            return result;
        }
        
        if (expr[left] == '|'){
            int p1, p2;
            result = false;
            p1 = left + 2;
            while (true){
                p2 = find_comma(expr, p1, right-1);
                result = result || solve(expr, p1, p2);
                if (p2 == right-1) break;
                p1 = p2 + 1;
            }
            return result;
        }
        else {
            cout << "wrong" << endl;
            return false;
        }
    }
    
public:
    bool parseBoolExpr(string expression) {
        bracket_match(expression);
        return solve(expression, 0, expression.length());
    }
};
