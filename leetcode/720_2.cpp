struct TrieNode{
    bool is_end;
    TrieNode* next[26];
    
    TrieNode():is_end(false){
        for (int i=0;i<26;++i) next[i] = NULL;
    }
};

class Solution {

    TrieNode* root;
    string result, state;
    
    void insert(const string &st){
        TrieNode* cur = root;
        for (char ch : st){
            if (cur->next[ch-'a'] == NULL)
                cur->next[ch-'a'] = new TrieNode();
            cur = cur->next[ch-'a'];
        }
        cur->is_end = true;
    }
    
    void dfs(TrieNode* cur){
        if (state.size() > result.size()) result = state;
        for (int i=0;i<26;++i)
            if (cur->next[i] != 0 && cur->next[i]->is_end){
                state.push_back('a' + i);
                dfs(cur->next[i]);
                state.pop_back();
            }
    }
    
public:
    string longestWord(vector<string>& words) {
        root = new TrieNode();
        for (string &s : words)
            insert(s);
        dfs(root);
        return result;
    }
};
