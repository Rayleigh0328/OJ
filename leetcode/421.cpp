struct TrieNode{
    TrieNode* next[2];
    
    TrieNode(){
        next[0] = next[1] = NULL;
    }
};

class Solution {
    
    const int width = 31;
    
    vector<int> convert_to_array(int x){
        vector<int> result(width, 0);
        for (int i=0;i<width;++i)
            if (x & (1<<i)) result[30-i] = 1;
        return result;
    }
    
    void insert(TrieNode* root, const vector<int> &a){
        TrieNode *current = root; 
        for (int x : a){
            if (current->next[x] == NULL){
                current->next[x] = new TrieNode();
            }
            current = current->next[x];
        }
    }
    
    int traverse(TrieNode* root, const vector<int> &a){
        TrieNode *current = root;
        int result = 0, tmp;
        for (int i=0;i<width;++i){
            tmp = a[i];
            if (current->next[tmp] == NULL){
                current = current->next[1-tmp];
            }
            else {
                result += (1<<(30-i));
                current = current->next[tmp];
            }
        }
        return result;
    }
    
public:
    int findMaximumXOR(vector<int>& a) {
        TrieNode *root = new TrieNode();
        for (auto x : a)
            insert(root, convert_to_array(x));
        int ans = 0;
        for (auto x : a)
            ans = max(ans, traverse(root, convert_to_array(~x)));
        return ans;
    }
};
