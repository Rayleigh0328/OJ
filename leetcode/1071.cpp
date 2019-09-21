class Solution {
public:
    
    int gcd(int x, int y){
        if (x % y == 0) return y;
        return gcd(y, x%y);
    }
    string gcdOfStrings(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        int len = gcd(n,m);
        string result = str1.substr(0,len);
        for (int i=0;i<str1.length();++i)
            if (str1[i] != result[i%len]) return "";
        for (int i=0;i<str2.length();++i)
            if (str2[i] != result[i%len]) return "";
        return result;
    }
};
