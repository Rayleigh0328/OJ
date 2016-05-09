class WordDictionary {
private:
    struct TrieNode{
        bool word_flag;
        TrieNode* children[26];
        
        TrieNode(bool flag)
        {
            word_flag = flag;
            for (int i=0;i<26;++i) children[i] = NULL;
        }
    };
    
    TrieNode *root;
    
    bool search(TrieNode* cur, const string &st, int pos)
    {
        if (cur == NULL) return false;
        if (pos == st.length()) return cur->word_flag;
        
        if (st[pos] == '.')
        {
            bool ans = false;
            for (int i=0;i<26;++i) 
                ans = ans || search(cur->children[i], st, pos+1);
            return ans;
        }
        else
        {
            return search(cur->children[st[pos]-'a'], st, pos+1);
        }
    }
    
public:
    WordDictionary()
    {
        root = new TrieNode(false);
    }

    // Adds a word into the data structure.
    void addWord(string word) 
    {
        if (word.empty()) root->word_flag = true;
        
        TrieNode* cur = root;
        for (int i=0;i<word.size();++i)
        {
            if (cur->children[word[i]-'a'] == NULL)
                cur->children[word[i]-'a'] = new TrieNode(i == word.size()-1);
            cur = cur->children[word[i]-'a'];
        }
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) 
    {
        return search(root, word, 0);
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");