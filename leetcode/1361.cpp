class Solution {
    void dfs(int k, vector<bool>& visited, const vector<int> &lc, const vector<int> &rc){
        visited[k] = true;
        if (lc[k] != -1 && !visited[lc[k]]) dfs(lc[k], visited, lc, rc);
        if (rc[k] != -1 && !visited[rc[k]]) dfs(rc[k], visited, lc, rc);
    }
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> in_degree(n,0);
        for (auto x : leftChild) if (x>=0) ++in_degree[x];
        for (auto x : rightChild) if (x>=0) ++in_degree[x];
        int sum = 0;
        for (int i=0;i<n;++i)
            sum += in_degree[i];
        if (sum != n-1) return false;
        
        int root = -1;
        for (int i=0;i<n;++i)
            if (in_degree[i] == 0) root = i;
        if (root == -1) return false;
        
        vector<bool> visited(n,false);
        dfs(root, visited, leftChild, rightChild);
        
        for (auto x : visited)
            if (!x) return false;
        return true;
    }
};
