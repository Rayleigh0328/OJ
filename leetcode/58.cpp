class Solution {
public:
    int lengthOfLastWord(string s) {
        s.erase(s.find_last_not_of(" ")+1);
        int pos = s.find_last_of(' ');
        string last;
        if (pos == string::npos)
            last = s;
        else
            last = s.substr(pos+1);
        return last.length();
    }
};