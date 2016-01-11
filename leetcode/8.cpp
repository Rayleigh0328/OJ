// Pay attention to special cases
// 1: + 
// 2: more than 1 sign
// 3: trim
// 4: out of 32-bit range
// 5: 32-bit range is -2147483648 to 2147483647

class Solution {
public:
    inline std::string trim_right_copy( const std::string& s, const std::string& delimiters = " \f\n\r\t\v" )
    {
        return s.substr( 0, s.find_last_not_of( delimiters ) + 1 );
    }

    inline std::string trim_left_copy( const std::string& s, const std::string& delimiters = " \f\n\r\t\v" )
    {
        return s.substr( s.find_first_not_of( delimiters ) );
    }
    
    inline std::string trim_copy( const std::string& s, const std::string& delimiters = " \f\n\r\t\v")
    {
        return trim_left_copy( trim_right_copy( s, delimiters ), delimiters );
    }
    
    int myAtoi(string str) {
        if (str == "") return 0;
        str = trim_copy(str);
        
        int mult = 1;
        int pos = 0;
        if (str[0] == '-')
        {
            mult = -1;
            pos = 1;
        }
        else 
            if (str[0]=='+') pos = 1;

        long long result = 0ll;
        for (int i=pos;i<str.size();++i)
        {
            if(!isdigit(str[i])) break;
            result = result * 10ll + (long long)(str[i] - '0');
            if (result > INT_MAX && mult==1) return INT_MAX;
            if (result > INT_MAX + 1ll && mult == -1) return -INT_MAX - 1;
        }
        return result * mult;
    }
};