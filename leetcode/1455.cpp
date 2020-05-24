class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        
        int pos = sentence.find(searchWord);
        while (pos != 0 && pos != string::npos && sentence[pos-1]!=' ')
            pos = sentence.find(searchWord, pos + 1);
        
        if (pos == string::npos) return -1;
        if (pos == 0) return 1;
        
        int space_count = 0;
        for (int i=0;i<pos;++i)
            if (sentence[i] == ' ') ++space_count;
        return space_count + 1;
    }
};
