class Solution {
private:
    string trim(string s)
    {
        if (s.empty()) return s;
        
        size_t first = s.find_first_not_of(' ');
        if (first == string::npos) first = s.length();
        size_t last = s.find_last_not_of(' ');
        return s.substr(first, last-first+1);
    }
    
    bool is_int(string s)
    {
        if (s.empty()) return false;
        for (int i=0;i<s.length();++i)
            if (!isdigit(s[i])) return false;
        return true;
    }
    
    bool is_float(string s)
    {
        size_t pos_dot = s.find_first_of('.');
        if (pos_dot == string::npos)
        {
            return is_int(s);
        }
        else
            if (pos_dot == 0)
            {
                return is_int(s.substr(1));
            }
            else 
                if (pos_dot == s.length()-1)
                {
                    return is_int(s.substr(0,pos_dot));
                }
                else
                {
                    return is_int(s.substr(0,pos_dot)) && is_int(s.substr(pos_dot+1));
                }
    }
    
public:
    bool isNumber(string s) 
    {
        if (s.empty()) return false;
        s = trim(s);
        if (s[0] == '+' || s[0] == '-')
            s = s.substr(1);
            
        size_t pos_e = s.find_first_of('e');
        if (pos_e == string::npos) return is_float(s);
        else
        {
            bool ans = true;
            ans = ans && is_float(s.substr(0,pos_e));
            if (pos_e == s.length() - 1) return false;
            else
                if (s[pos_e+1] == '+' || s[pos_e + 1] == '-')
                    ans = ans && is_int(s.substr(pos_e + 2));
                else
                    ans = ans && is_int(s.substr(pos_e + 1));
            return ans;
        }
            
    }
};