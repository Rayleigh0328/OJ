class Solution {
    
    bool is_subsequence(string &p, string &s){
        int pos = 0;
        for (int i=0;i<p.size();++i){
            while (pos < s.size() && s[pos] != p[i]) ++pos;
            if (i==p.size()-1 && pos < s.size()) return true; 
            ++pos;
        }
        return false;
    }
    
    bool better(string &x, string &y){
        if (x.size() > y.size()) return true;
        if (x.size() < y.size()) return false;
        return (x < y);
    }
    
public:
    string findLongestWord(string s, vector<string>& d) {
        string result;
        for (auto &st : d)
            if (is_subsequence(st,s) && better(st,result))
                result = st;
        return result;
    }
};
