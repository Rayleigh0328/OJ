class Solution {
    char flip(char ch){
        if (ch == '0') return '1';
        return '0';
    }
public:
    int minFlips(string a) {
        char cur = '0';
        int result = 0;
        for (int i=0;i<a.size();++i)
            if (a[i] != cur) {
                cur = flip(cur);
                ++result;
            } 
        return result;
    }
};
