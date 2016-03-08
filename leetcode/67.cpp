class Solution {
public:
    string addBinary(string a, string b) {
        // make equal length
        while (a.length() < b.length()) a = '0' + a;
        while (b.length() < a.length()) b = '0' + b;
        int c = 0;
        string ans;
        for (int i=a.length()-1;i>=0;--i)
        {
            int tmp = c + a[i]-'0' + b[i]-'0';
            if (tmp > 1)
            {
                tmp = tmp - 2;
                c = 1;
            }
            else
                c = 0;
            ans = (char)(tmp + '0') + ans;
        }
        if (c == 1)
            ans = '1' + ans;
        int pos = 0;
        while (pos < ans.length() - 1 && ans[pos]=='0') ++pos;
        return ans.substr(pos);
    }
};