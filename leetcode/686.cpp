class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string c(a); 
        int count = 1;
        while (c.length() < b.length()) {c += a; ++count;}
        if (c.find(b) != string::npos) return count;
        c+=a; ++count;
        if (c.find(b) != string::npos) return count;
        return -1;
    }
};
