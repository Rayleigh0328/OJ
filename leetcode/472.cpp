struct TrieNode{
    bool is_end;
    TrieNode* next[26];
    
    TrieNode(){
        is_end = false;
        for (int i=0;i<26;++i) next[i]=NULL;
    }
};

class Solution {

    TrieNode* root;
    
    void insert(const string& st){
        TrieNode* cur = root;
        for (char ch : st){
            if (cur->next[ch-'a'] == NULL)
                cur->next[ch-'a'] = new TrieNode();
            cur = cur->next[ch-'a'];
        }
        cur->is_end = true;
    }
    
    bool check(const string &st, int pos){
        // printf("check %s start pos %d\n", st.c_str(), pos);
        TrieNode* cur = root;
        for (int i=pos;i<st.size();++i){
            char ch = st[i];
            cur = cur->next[ch-'a'];
            if (cur == NULL) break;
            if (cur->is_end){
                if (i == st.size()-1) return (pos>0);
                if (check(st, i+1)) return true;
            }
        }
        return false;
    }
    
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        root = new TrieNode();
        for (const string &word : words) insert(word);
        // printf("insertion done\n");
        vector<string> result;
        for (const string &word : words)
            if (check(word,0)) result.push_back(word);
        return result;
    }
};
