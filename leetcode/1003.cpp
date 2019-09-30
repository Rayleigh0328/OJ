class Solution {
public:
    bool isValid(string str) {
        vector<char> s;
        for (int i=0; i<str.length();++i){
            s.push_back(str[i]);
            if (
                s.size() >=3 && 
                s[s.size()-3]=='a' &&
                s[s.size()-2]=='b' &&
                s[s.size()-1]=='c'
            ) {
                for (int j = 0; j<3;++j) s.pop_back();
            }
        }
        return s.empty();
    }
};
