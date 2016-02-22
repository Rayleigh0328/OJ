class Solution {
public:
    bool isPalindrome(string s) {
        string fin="";
        for (int i=0;i<s.size();++i)
            if (isalnum(s[i])) fin += tolower(s[i]);
        for (int i=0;i<fin.size();++i)
            if (fin[i] != fin[fin.size()-1-i]) return false;
        return true;       
    }
};