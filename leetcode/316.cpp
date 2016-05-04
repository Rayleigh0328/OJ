class Solution {
public:
    string removeDuplicateLetters(string s) 
    {
        string ans = "";
        unordered_set<char> alphabet;
        alphabet.clear();
        for (int i=0;i<s.size();++i)
            alphabet.insert(s[i]);
        int rounds = alphabet.size();
        int left = 0, right;
        for (int i=0;i<rounds;++i)
        {
            unordered_set<char> cur_set;
            cur_set.clear();
            for (right = s.size()-1; right>=left;--right)
            {
                if (alphabet.find(s[right]) != alphabet.end()) 
                    cur_set.insert(s[right]);
                if (cur_set.size() == alphabet.size())
                    break;
            }
            // cout << "right: " << right << endl;
            while (alphabet.find(s[left]) == alphabet.end()) ++left;
            
            for (int new_pos = left; new_pos <= right; ++new_pos)
                if (alphabet.find(s[new_pos]) != alphabet.end() && s[left] > s[new_pos])
                    left = new_pos;
            ans += s[left];
            alphabet.erase(s[left]);
            
            // cout << "\tans: " << ans << endl;
        }
        return ans;
    }
};