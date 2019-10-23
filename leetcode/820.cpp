// Trie. reverse word then insert
// answer is the sum of depth of all leaf node

struct Node{
    Node* next[26];
    int depth;
    
    Node(int d):depth(d){
        for (int i=0;i<26;++i) next[i] = NULL;
    }
};

void insert(const string& st, int pos, Node* n){
    if (pos == st.size()) return;
    char ch = st[pos];
    if (n->next[ch-'a'] == NULL){
        n->next[ch-'a'] = new Node(n->depth+1);
    }
    insert(st, pos + 1, n->next[ch-'a']);
}

void dfs(Node* n, int& ans){
    bool is_leaf = true;
    for (int i=0;i<26;++i)
        if (n->next[i] != NULL){
            is_leaf = false;
            dfs(n->next[i], ans);
        }
    if (is_leaf) ans += n->depth + 1;
}

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        Node* root = new Node(0);
        string tmp;
        for (string word : words){
            tmp = word;
            reverse(tmp.begin(), tmp.end());
            insert(tmp,0,root);
        }
        int ans=0;
        dfs(root,ans);
        return ans;
    }
};
