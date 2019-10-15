struct Run{
    char ch;
    int len;
    Run(char c, int l):ch(c), len(l){}
};

class Solution {
    
    vector<Run> encode(string s){
        vector<Run> ans;
        for (char c : s){
            if (ans.empty() || ans.back().ch != c){
                ans.push_back(Run(c,1));
            }
            else ++ans.back().len;
        }
        return ans;
    }
    
public:
    bool isLongPressedName(string s1, string s2) {
        // run length coding
        // for each run, s2 >= s1
        vector<Run> code1 = encode(s1);
        vector<Run> code2 = encode(s2);
        if (code1.size() != code2.size()) return false;
        for (int i=0;i<code1.size();++i){
            if (code1[i].ch != code2[i].ch || code1[i].len > code2[i].len) return false;
        }
        return true;
    }
};
