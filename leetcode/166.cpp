class Solution {
private:
    string get_ans(bool add_neg, int int_part, vector<int>& digit, int pos)
    {
        string ans = "";
        if (add_neg) ans += '-';
        ans += to_string(int_part);
        ans += ".";
        if (pos == -1)
        {
            for (int i=0;i<digit.size();++i)
                ans += to_string(digit[i]);
            return ans;
        }
        
        for (int i=0;i<pos;++i)
            ans += to_string(digit[i]);
        ans += "(";
        for (int i=pos;i<digit.size();++i)
            ans += to_string(digit[i]);
        ans += ")";
    }
    
public:
    string fractionToDecimal(int x, int y) 
    {
        long long a = x;
        long long b = y;
        if (a < 0 && b < 0)
        {
            a = -a;
            b = -b;
        }
        if (a % b == 0) return to_string(a/b);
        long long int_part = a/b;
        bool add_neg = false;
        if (int_part == 0 && (a<0 || b<0))
            add_neg = true;
        
        a = a%b;
        if (a < 0) a = -a;
        if (b < 0) b = -b;
        
        map<long long, int> rem;
        rem.clear();
    
        vector<int> digit;
        digit.clear();
        
        while (true)
        {
            a *= 10;
            // can be divided
            if (a % b == 0)
            {
                digit.push_back(a/b);
                return get_ans(add_neg, int_part, digit, -1);
            }
            
            // can not be divided
            if (rem.find(a) != rem.end())
            {
                // recur
                return get_ans(add_neg, int_part, digit, rem[a]);
            }
            
            rem.emplace(a, digit.size());
            digit.push_back(a/b);
            a = a % b;
        }
    }
};