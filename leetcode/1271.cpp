class Solution {
    
    char convert_to_char(int x){
        if (x == 0) return 'O';
        if (x == 1) return 'I';
        if(x < 10) return 'X';
        else return 'A' + x - 10;
    }
    
public:
    string toHexspeak(string s) {
        long long n = stoll(s);
        string tmp;
        while (n > 0){
            tmp += convert_to_char(n % 16);
            n /= 16;
        }
        reverse(tmp.begin(), tmp.end());
        for (char ch : tmp)
            if (ch == 'X') return "ERROR";
        return tmp;
    }
};
