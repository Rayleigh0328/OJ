class Solution {
    
    void to_set(TreeNode* p, unordered_set<int>& s){
        if (p == NULL) return;
        s.emplace(p->val);
        to_set(p->left, s);
        to_set(p->right, s);
    }
    
public:
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        unordered_set<int> s1;
        unordered_set<int> s2;
        to_set(root1, s1);
        to_set(root2, s2);
        
        for (auto x : s1){
            if (s2.find(target-x) != s2.end()) return true;
        }
        return false;
    }
