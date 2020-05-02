class Solution {
    
    bool check(string a, string b){
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        for (int i=0;i<a.size();++i)
            if (a[i] < b[i]) return false;
        return true;
    }
    
public:
    bool checkIfCanBreak(string s1, string s2) {
        return (check(s1,s2) || check(s2,s1));
    }
};
