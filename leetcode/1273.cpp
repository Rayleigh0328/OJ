struct Node{
    int val;
    int sum;
    bool removed;
    vector<Node*> next;
    
    Node():Node(0){}
    
    Node(int val):val(val), sum(val), removed(false){
    }
};

class Solution {
    
    int result;
    
    void dfs_sum(Node* cur){
        if (cur == NULL) return ;
        for (auto e : cur->next) dfs_sum(e);
        for (auto e : cur->next) cur->sum += e->sum;
    }
    
    void dfs_remove(Node* cur){
        if (cur->sum != 0) ++result;
        else return;
        for (auto e : cur->next)
            dfs_remove(e);
    }
    
public:
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
        vector<Node*> a(nodes);
        for (int i=0;i<nodes;++i) a[i] = new Node(value[i]);
        for (int i=0;i<nodes;++i){
            if (parent[i] != -1) 
                a[parent[i]]->next.push_back(a[i]);
        }
        dfs_sum(a[0]);
        result = 0;
        dfs_remove(a[0]);
        return result;
    }
};
