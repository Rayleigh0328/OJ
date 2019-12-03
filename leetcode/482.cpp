class Solution {

    char to_upper(char ch){
        if ('a' <= ch && ch <= 'z') return ch-'a'+'A';
        else return ch;
    }
    
public:
    string licenseKeyFormatting(string s, int k) {
        string tmp;
        for (char ch : s)
            if (ch != '-') tmp.push_back(ch);
        reverse(tmp.begin(), tmp.end());
        string ans;
        int count = 0;
        for (char ch : tmp){
            ans.push_back(to_upper(ch));
            if (++count % k == 0) ans.push_back('-');
        }
        if (ans.back() == '-') ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
