class Solution {
    
    int count(const string &st, char ch){
        int result = 0;
        for (int i=0;i<st.size();++i)
            if (st[i] == ch) ++result;
        return result;
    }
    
public:
    int maxScore(string s) {
        string sl, sr;
        int result = 0;
        for (int i=0;i<s.size()-1;++i){
            sl = s.substr(0,i+1);
            sr = s.substr(i+1);
            result = max(result, count(sl,'0') + count(sr,'1'));
        }
        return result;
    }
};
