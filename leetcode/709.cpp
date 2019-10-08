class Solution {
    char lc(char ch){
        if ('A' <= ch && ch <='Z') 
            return ch - 'A' + 'a';
        else 
            return ch;
    }
public:
    string toLowerCase(string str) {
        string ans;
        for (int i=0;i<str.length();++i){
            ans += lc(str[i]);
        }
        return ans;
    }
};
