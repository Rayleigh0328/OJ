class Solution {
private:
    string fin;
    map<int, int> match;
    
    void init_match()
    {
        match.clear();
        stack<int> s;
        while (!s.empty()) s.pop();
        for (int i=0;i<fin.size();++i)
        {
            if (fin[i] == '(') s.push(i);
            if (fin[i] == ')') 
            {
                match[i] = s.top();
                s.pop();
            }
        }
    }
    
    int solve(int left, int right)
    {
        //cout << "[" << left << "," << right << "]"<<endl;
        if (fin[right]==')' && match[right] == left) return solve(left+1, right-1);
        
        int ad = right;
        while (ad >=left)
        {
            if (fin[ad] == ')') 
            {
                ad = match[ad] - 1;
                continue;
            }
            if (fin[ad] == '+') return solve(left, ad-1) + solve(ad+1, right);
            if (fin[ad] == '-') return solve(left, ad-1) - solve(ad+1, right);
            --ad;
        }
    
        string sub_st = fin.substr(left, right-left+1);
        return atoi(sub_st.c_str());
    }
public:
    int calculate(string s) 
    {
        fin = "";
        for (int i=0;i<s.size();++i)
            if (s[i] == '(' || s[i]==')' || s[i] == '+' || s[i] == '-' || isdigit(s[i]))
                fin += s[i];
        
        init_match();
        
        return solve(0, fin.size()-1);
    }
};