class Solution {
private: 
    vector<string> result;
    string s;
    long long tar;
    
    long long to_int(string tmp)
    {
        long long ans = 0;
        for (int i=0;i<tmp.length();++i)
            ans = ans * 10 + tmp[i] - '0';
        return ans;
    }
    
    void solve(int pos, long long cur, string ans, long long prev)
    {
        // process the whole string
        if (pos == s.length() && tar == cur)
            result.push_back(ans);
            
        // leading zero
        if (s[pos] == '0')
        {
            if (pos != 0)
            {
                solve(pos+1, cur, ans+"+0", 0);
                solve(pos+1, cur, ans+"-0", 0);
                solve(pos+1, cur-prev, ans+"*0",0);
            }
            else
            {
                solve(1,0,"0",0);
            }
        }
        else
        {
            for (int i=1; pos+i-1<s.length(); ++i)
            {
                string tmp = s.substr(pos,i);
                //long long val = stoi(tmp);
                long long val = to_int(tmp);
                if (pos != 0)
                {
                    solve(pos+i, cur+val, ans+"+"+tmp, val);
                    solve(pos+i, cur-val, ans+"-"+tmp, -val);
                    solve(pos+i, cur-prev+prev*val, ans+"*"+tmp, prev*val);
                }
                else
                {
                    solve(i, val, tmp, val);
                }
            }
        }
    }
public:
    vector<string> addOperators(string num, int target) 
    {
        s = num;
        tar = target;
        
        result.clear();
        solve(0,0,"",0);
        
        return result;
    }
};