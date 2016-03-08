const int range = 'z' - 'a' + 1;

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode* child[range];
    int word_count;
    
    TrieNode() {
        for (int i=0;i<range;++i)
            child[i] = NULL;
        word_count = 0;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *tmp = root;
        for (int i=0;i<word.length();++i)
        {
            if (tmp->child[word[i]-'a'] == NULL) tmp->child[word[i]-'a'] = new TrieNode();
            tmp = tmp->child[word[i]-'a'];
        }
        ++tmp->word_count;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* tmp = root;
        for (int i=0;i<word.length();++i)
            if (tmp == NULL) return false;
            else tmp = tmp->child[word[i]-'a'];
        if (tmp!= NULL && tmp->word_count > 0) return true;
        else return false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* tmp = root;
        for (int i=0;i<prefix.length();++i)
            if (tmp == NULL) return false;
            else tmp = tmp->child[prefix[i]-'a'];
        if (tmp != NULL) return true;
        else return false;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");