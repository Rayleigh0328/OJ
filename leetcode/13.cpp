class Solution {
public:
    int romanToInt(string s) 
    {
        map<char,int> mp;
        mp.clear();
        mp.emplace('I',1);
        mp.emplace('V',5);
        mp.emplace('X',10);
        mp.emplace('L',50);
        mp.emplace('C',100);
        mp.emplace('D',500);
        mp.emplace('M',1000);
        
        int ans = 0;
        for (int i=0;i<s.size();++i)
            if (i<s.size()-1 && mp[s[i]] < mp[s[i+1]]) ans -= mp[s[i]];
            else ans += mp[s[i]];
        return ans;
    }
};