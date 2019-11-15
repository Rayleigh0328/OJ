class Solution {
    
    static bool is_digit(char ch){
        return '0' <= ch && ch <= '9';
    }
    
    static int f(const string &st){
        int pos = st.find(' ') + 1;
        return (is_digit(st[pos])?-1:pos);
    }
    
    static bool cmp(const string &x, const string &y){
        int pos_x = f(x);
        int pos_y = f(y);
        if (pos_x == -1 && pos_y == -1) return false;
        if (pos_x == -1 && pos_y != -1) return false;
        if (pos_x != -1 && pos_y == 1) return true;
        if (pos_x != -1 && pos_y != -1){
            if (x.substr(pos_x) < y.substr(pos_y)) return true;
            if (x.substr(pos_x) > y.substr(pos_y)) return false;
            return x.substr(0, pos_x) < y.substr(0, pos_y);
        }
        return true;
    }
    
    string trim_space(const string &st){
        string ans;
        int pos = 0;
        // leading zero
        while (st[pos] == ' ') ++pos;
        // zeros in the middle
        for (;pos<st.length();++pos)
            if (st[pos] != ' ') ans += st[pos];
            else if (ans.back() != ' ') ans += st[pos];
        // trailing zero
        while (ans.back() == ' ') ans.pop_back();
        return ans;
    }
    
    void trim_space(vector<string>& v){
        for (int i=0;i<v.size();++i)
            v[i] = trim_space(v[i]);
    }
    
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        trim_space(logs);
        stable_sort(logs.begin(), logs.end(), cmp);
        return logs;
    }
};
