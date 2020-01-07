class Solution {
public:
    vector<int> xorQueries(vector<int>& a, vector<vector<int>>& queries) {
        int n = a.size();
        vector<int> f(n, 0);
        f[0] = a[0];
        for (int i=1;i<a.size();++i)
            f[i] = f[i-1] ^ a[i];
        
        vector<int> result;
        for (auto query : queries){
            int left = query[0], right = query[1];
            if (left == 0) result.push_back(f[right]);
            else result.push_back(f[right] ^ f[left-1]);
        }
        return result;
    }
};
