class Solution {
    
bool check(string& s)
{
    if (s[0] == '0' && s.length()>1) return true;
    if (s.length() > 4) return true;
    return false;
}
    
void solve(int a, int b, int c, string &s, vector<string> &ans)
{
    //if (a>4 || b-a>4 || c-b>4 || s.length()-c > 4) return;
    string s1 = s.substr(0,a);
    string s2 = s.substr(a,b-a);
    string s3 = s.substr(b,c-b);
    string s4 = s.substr(c);
    
    if (check(s1) || check(s2) || check(s3) || check(s4)) return ;
    //cout << s1 << " " << s2 << " " << s3 << " " << s4 << endl;
    
    if (stoi(s1) <= 255 && stoi(s2) <= 255 && stoi(s3) <= 255 && stoi(s4)<=255)
        ans.push_back(s1+"."+s2+"."+s3+"."+s4);
}
    
public:
    vector<string> restoreIpAddresses(string s) 
    {
        
        vector<string> ans;
        ans.clear();
        int len = s.length();
        if (len > 20) return ans;
        for (int i=1;i<len;++i)
            for (int j=i+1;j<len;++j)
                for (int k=j+1;k<len;++k)
                        solve(i,j,k,s,ans);
        return ans;
    }
};