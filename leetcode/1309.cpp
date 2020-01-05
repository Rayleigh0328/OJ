class Solution {
    
    char convert(char ch){
        return ch - '1' + 'a'; 
    }
    
    char convert(char ch1, char ch2){
        int code = (ch1 - '0') * 10 + ch2 - '0';
        return code - 10 + 'j';
    }
    
public:
    string freqAlphabets(string s) {
        string result;
        for (int i = s.size()-1; i>=0; --i)
            if (s[i] == '#'){
                result = convert(s[i-2], s[i-1]) + result;
                i-=2;
            }
            else{
                result = convert(s[i]) + result;
            }
        return result;
    }
};
