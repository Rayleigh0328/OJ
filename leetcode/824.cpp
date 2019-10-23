class Solution {
    unordered_set<char> vowel{'a','e','i','o','u','A','E','I','O','U'};
public:
    string toGoatLatin(string S) {
        stringstream ss(S);
        string word;
        int count = 0;
        string ans;
        while (ss >> word){
            char ch = word[0];
            ++count;
            if (vowel.find(ch) != vowel.end()) word += "ma";
            else {
                word = word.substr(1);
                word += ch;
                word += "ma";
            }
            word += string(count, 'a');
            ans += (count > 1?" ":"") + word;
        }
        return ans;
    }
};
