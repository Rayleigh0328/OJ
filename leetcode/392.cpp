class Solution {
public:
    bool isSubsequence(string s, string t) {
        // vector< set<int> > for each character, have a set records its position on t
        // set pos = 0 indicate the start matching position in t 
        // foreach ch in s, move pos to (*sets[ch-'a'].lower_bound(pos+1)) + 1
        // if for some ch, can not move pos, then return false
        
        vector<set<int>> pos_set(26);
        for (int i=0; i<t.size();++i) pos_set[t[i]-'a'].emplace(i);
        
        int pos = 0;
        for (char ch : s){
            auto it = pos_set[ch-'a'].lower_bound(pos);
            if (it == pos_set[ch-'a'].end()) return false;
            pos = (*it) + 1;
        }
        return true;
    }
};
