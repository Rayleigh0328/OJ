class Solution {
    
    int is_vowel(char ch){
        if (ch == 'a') return 1;
        if (ch == 'e') return 1;
        if (ch == 'i') return 1;
        if (ch == 'o') return 1;
        if (ch == 'u') return 1;
        return 0;
    }
    
public:
    int maxVowels(string s, int k) {
        int result = 0;
        
        if (k >= s.length()){
            for (int i=0;i<s.length();++i) 
                result += is_vowel(s[i]);
            return result;
        }
        
        int cur = 0;
        for (int i=0;i<k;++i)
            cur += is_vowel(s[i]);
        result = cur;
        
        for (int i=k;i<s.length();++i){
            cur += is_vowel(s[i]);
            cur -= is_vowel(s[i-k]);
            result = max(result, cur);
        }
        return result;
    }
};
