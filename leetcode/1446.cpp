class Solution {
public:
    int maxPower(string s) {
        char cur='$';
        int count=0;
        int result = 0;
        for (int i=0;i<s.size();++i){
            char ch = s[i];
            if (ch != cur){
                cur = ch;
                count = 0;
            }
            result = max(result, ++count);
        }
        return result;
    }
};
