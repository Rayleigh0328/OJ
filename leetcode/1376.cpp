class Solution {
    int root;
    int n;
    vector<int> f;
    vector<int> parent;
    vector<int> time;
    
    int solve(int k){
        if (f[k] != -1) return f[k];
        if (parent[k] == -1) return (f[k] = 0);
        return f[k] = (solve(parent[k]) + time[parent[k]]); 
    }
public:
    int numOfMinutes(int nn, int headID, vector<int>& manager, vector<int>& informTime) {
        root = headID;
        n = nn;
        parent = manager;
        time = informTime;
        
        f = vector(n, -1);
        int result = -1;
        for (int i=0;i<n;++i)
            result = max(result, solve(i));
        return result;
    }
};
