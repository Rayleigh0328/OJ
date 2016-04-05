class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
        map<char,char> mp;
        map<char,char> mp_back;
        mp.clear();
        mp_back.clear();
        
        if (s.length() != t.length()) return false;
        
        for (int i=0;i<s.length();++i)
        {
            char a = s[i];
            char b = t[i];
            if (mp.find(a) ==  mp.end())
                mp[a] = b;
            else
                if (mp[a] != b) return false;
            
            if (mp_back.find(b) == mp_back.end())
                mp_back[b] = a;
            else
                if (mp_back[b] != a) return false;
        }
        
        return true;
    }
};