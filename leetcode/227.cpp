class Solution {
public:
    int calculate(string raw) 
    {
        // remove all spaces
        string s = "";
        for (int i=0;i<raw.size();++i)
            if (raw[i] != ' ') s += raw[i];
        
        // cout << "s: " << s << endl;
        
        vector<int> operand;
        operand.clear();
        operand.push_back(0);
        vector<char> op;
        op.clear();
        
        for (int i=0;i<s.size();++i)
            if (isdigit(s[i]))
                operand[operand.size() - 1] = operand[operand.size() - 1] * 10 + s[i] - '0';
            else
            {
                op.push_back(s[i]);
                operand.push_back(0);
            }
                
        // cout << "operand[]: ";
        // for (int i=0;i<operand.size();++i)
        //     cout << operand[i] << " " ;
        // cout << endl;
        
        vector<int> a;
        a.clear();
        a.push_back(operand[0]);
        for (int i=0;i<op.size();++i)
        {
            a.push_back(operand[i+1]);
            if (op[i] == '*')
            {
                int y = a.back(); 
                a.pop_back();
                int x = a.back();
                a.pop_back();
                a.push_back(x*y);
            }
            else
                if (op[i] == '/')
                {
                    int y = a.back(); 
                    a.pop_back();
                    int x = a.back();
                    a.pop_back();
                    a.push_back(x/y);
                }
        }
        
        
        vector<int> b;
        b.clear();
        b.push_back(a[0]);
        int pos_a = 1;
        
        for (int i=0;i<op.size();++i)
            if (op[i] == '+' || op[i] == '-')
            {
                b.push_back(a[pos_a++]);
                
                int y = b.back();
                b.pop_back();
                int x = b.back();
                b.pop_back();
                
                if (op[i]=='+')
                    b.push_back(x+y);
                else
                    b.push_back(x-y);
            }
        
        return b.front();
    }
};