class Solution {
    
    void get_fp(string st, vector<int>& fp){
        for (int i=0;i<fp.size();++i) fp[i] = 0;
        for (int i=0;i<st.length();++i) ++fp[st[i]-'a'];
    }
    
    bool fp_contains(const vector<int>& fp, const vector<int>& sub_fp){
        for (char ch = 'a'; ch <='z'; ++ch){
            if (fp[ch-'a'] < sub_fp[ch-'a']) return false;
        }
        return true;
    }
    
public:
    int countCharacters(vector<string>& words, string chars) {
        int ans = 0;
        vector<int> chars_fp('z'-'a'+1);
        vector<int> word_fp('z'-'a'+1);
        get_fp(chars, chars_fp);
        for (string word : words){
            get_fp(word, word_fp);
            if (fp_contains(chars_fp, word_fp)) ans += word.length();
        }
        return ans;
    }
};
