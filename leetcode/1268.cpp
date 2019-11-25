struct TrieNode{
    int is_end;
    string st;
    vector<TrieNode*> next;
    
    TrieNode(){
        is_end = 0;
        st = "";
        next = vector<TrieNode*>(26, NULL);
    }
};

class Solution {
    
    void insert(TrieNode* cur, const string& st, int pos){
        if (pos == st.size()) {
            ++cur->is_end;
            cur->st = st;
            return;
        }
        int ind = st[pos] - 'a';
        if (cur->next[ind] == NULL)
            cur->next[ind] = new TrieNode();
        insert(cur->next[ind], st, pos+1);
    }
    
    bool dup(string &st, vector<string> &a){
        for (string &e : a)
            if (e.compare(st) == 0) return true;
        return false;
    }
    
    void dfs(TrieNode* cur, vector<string>& result){
        if (result.size() == 3) return;
        if (cur == NULL) return;
        for (int i=0;i<cur->is_end;++i)
            if (result.size() < 3) result.push_back(cur->st);
        for (int i=0;i<26;++i)
            dfs(cur->next[i], result);
    }
    
    vector<string> get_suggest(TrieNode* cur){
        vector<string> result;
        dfs(cur, result);
        return result;
    }
    
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        TrieNode* root = new TrieNode();
        for (const string &product : products)
            insert(root, product, 0);
        
        TrieNode* cur = root;
        vector<vector<string>> result;
        for (char ch : searchWord){
            if (cur != NULL) cur = cur->next[ch-'a'];
            result.push_back(get_suggest(cur));
        }
        return result;
    }
};
