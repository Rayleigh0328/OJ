class Solution {
    
    bool is_digit(char ch){
        return '0'<=ch && ch <='9';
    }
    
    bool is_a_to_f(char ch){
        if ('a'<=ch && ch<='f') return true;
        if ('A'<=ch && ch<='F') return true;
        return false;
    }
    
    bool check_ipv4(const string &st){
        for (char ch : st){
            if (ch != '.' && !is_digit(ch)) return false;
        }
        stringstream ss(st);
        int tmp;
        char ch;
        for (int i=0;i<4;++i){
            ss >> tmp;
            if (ss.fail() || tmp < 0 || tmp > 255) return false;
            if (i != 3) ss >> ch;
        }
        return ss.eof();
    }
    
    bool check_ipv6(const string &st){
        for (char ch : st){
            if (ch != ':' && !is_digit(ch) && !is_a_to_f(ch)) return false;
        }
        stringstream ss;
        ss << hex << st;
        int tmp;
        char ch;
        for (int i=0;i<8;++i){
            ss >> tmp;
            // cout << hex << tmp << endl;
            if (ss.fail() || tmp < 0 || tmp > 0xFFFF) return false;
            if (i != 7) ss >> ch;
        }
        return ss.eof();
    }
    
    bool has_leading_zero(const string &st, char delimiter){
        if (st[0] == '0' && st[1] != delimiter) return true;
        for (int i=0;i<st.size();++i)
            if (st[i] == delimiter)
                if (st[i+1] == '0' && !(i+2 >= st.size() || st[i+2]==delimiter)) 
                    return true;
        return false;
    }
    
    bool check_length(const string &st, char delimiter){
        vector<int> pos{-1};
        for (int i=0;i<st.size();++i)
            if (st[i] == delimiter) 
                pos.push_back(i);
        pos.push_back(st.size());
        for (int i=1;i<pos.size();++i)
            if (pos[i] - pos[i-1] > 5) return false;
        return true;
    }
    
public:
    string validIPAddress(string ip) {
        if (ip.find('.') != string::npos) {
            if (has_leading_zero(ip, '.')) return "Neither";
            if (check_ipv4(ip)) return "IPv4";
            else return "Neither";
        }
        else{
            if (!check_length(ip, ':')) return "Neither";
            if (check_ipv6(ip)) return "IPv6";
            else return "Neither";
        }
    }
};
