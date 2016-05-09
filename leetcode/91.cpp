class Solution {
private:
    int check_feasible(char ch1)
    {
        return ('0'< ch1 && ch1<='9')?1:0;
    }
    
    int check_feasible(char ch1, char ch2)
    {
        if (ch1 == '0') return 0;
        int data = (ch1 - '0') * 10 + ch2 - '0';
        return (1<= data && data <= 26)?1:0;
    }
public:
    int numDecodings(string s) 
    {
        if (s.empty()) return 0;
        if (s.size() == 1) return check_feasible(s[0]);
        
        int *f = new int [s.size()];
        
        f[0] = check_feasible(s[0]);
        f[1] = f[0] * check_feasible(s[1]) + check_feasible(s[0],s[1]);
        
        for (int i=2;i<s.size();++i)
            f[i] = f[i-1] * check_feasible(s[i]) + f[i-2] * check_feasible(s[i-1], s[i]);
        int ans = f[s.size() - 1];
        
        // for (int i=0;i<s.size();++i)
        //     cout << f[i] << " ";
        // cout << endl;
        
        delete [] f;
        return ans;
    }
};