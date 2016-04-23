class Solution {
private:
    bool is_vowel(char c)
    {
        c = tolower(c);
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
    }
public:
    string reverseVowels(string s) 
    {
        stack<char> st;
        for (int i=0;i<s.length();++i)
            if (is_vowel(s[i])) st.push(s[i]);
        for (int i=0;i<s.length();++i)
            if (is_vowel(s[i]))
            {
                s[i] = st.top();
                st.pop();
            }
        return s;
    }
};