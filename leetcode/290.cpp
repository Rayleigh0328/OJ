class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char, string>mp;
        map<string, char> back_mp;
        mp.clear();
        back_mp.clear();
        
        stringstream ss(str);
        
        string cur;
        int id = 0;
        while (ss >> cur)
        {
            if (id >= pattern.size()) return false;
            
            if (mp.find(pattern[id]) == mp.end()) 
            {
                mp.emplace(pattern[id], cur);
                if (back_mp.find(cur) != back_mp.end()) return false;
                back_mp.emplace(cur,pattern[id]);
            }
            else
                if (mp[pattern[id]] != cur) return false;
                
            //cout << pattern[id] << " " << cur << endl; 
            ++id;
        }
        //cout << id << endl;
        if (id != pattern.size()) return false;
        return true;
    }
};