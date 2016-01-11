class Solution {
private:
    int **f;
    bool solve(string& s, string& p, int s_pos, int p_pos)
    {
        if (s_pos == s.size() && p_pos == p.size()) return true;
        if (s_pos >s.size() || p_pos>p.size()) return false;
        
        if (f[s_pos][p_pos] == 0) return false;
        if (f[s_pos][p_pos] == 1) return true;
        
        
        
        bool result = false;
        if (p_pos < p.size() - 1 && p[p_pos + 1] == '*')
        {
            if (p[p_pos] == '.')
            {
                for (int k = s_pos; k<=s.size();++k) result = result || solve(s,p,k,p_pos + 2);
            }
            else
            {
                result = result || solve(s,p, s_pos, p_pos+2);
                for (int k = s_pos; k<s.size();++k) 
                    if (s[k] == p[p_pos]) result = result || solve(s,p,k+1,p_pos+2);
                    else break;
            }
        }
        else if (p[p_pos] == '.')
        {
            result = result || solve(s,p,s_pos+1,p_pos+1);
        }
        else
        {
            if (p[p_pos] == s[s_pos])
                result = result || solve(s,p,s_pos+1, p_pos+1);
        }
        
        f[s_pos][p_pos] = (result?1:0);
        return result;
    }
public:    
    bool isMatch(string s, string p) {
        f = new int* [s.size()+2];
        for (int i=0;i<s.size()+2;++i)
            f[i] = new int [p.size()+2];
            
        for (int i=0;i<s.size()+2;++i)
            for (int j=0;j<p.size()+2;++j)
                f[i][j] = -1;
                
        return solve(s,p,0,0);
    }
};