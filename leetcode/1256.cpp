class Solution {
public:
    string encode(int num) {
        if (num == 0) return "";
        int length = 0;
        while ((1<<length) <= num) num -= (1<<length++);
        string ans;
        for (int i=0;i<length;++i)
            ans = ((num & (1<<i))>0?'1':'0') + ans;
        return ans;
    }
};
