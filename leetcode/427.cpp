/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution {
    vector<vector<int>> g;
    int n;
    
    Node* solve(int r1, int r2, int c1, int c2){
        bool same_value = true;
        for (int i=r1;same_value && i<r2;++i)
            for (int j=c1;same_value && j<c2;++j)
                if (g[i][j] != g[r1][c1]){
                    same_value = false;
                }
        
        if(same_value)
            return new Node(g[r1][c1], true, NULL, NULL, NULL, NULL);
        else 
            return new Node(g[r1][c1], false, 
                            solve(r1, (r1+r2)/2, c1, (c1+c2)/2),
                            solve(r1, (r1+r2)/2, (c1+c2)/2, c2),
                            solve((r1+r2)/2, r2, c1, (c1+c2)/2),
                            solve((r1+r2)/2, r2, (c1+c2)/2, c2)
                           );
    }
    
public:
    Node* construct(vector<vector<int>>& grid) {
        g = grid;
        n = grid.size();
        return solve(0,n,0,n);
    }
};
