class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if (arr.empty()) return {};
        
        vector<int> a = arr;
        sort(a.begin(), a.end());
        const int n = a.size();
        unordered_map<int, int> rank;
        rank[a[0]] = 1;
        for (int i=1;i<n;++i)
            if (a[i] == a[i-1]) rank[a[i]] = rank[a[i-1]];
            else rank[a[i]] = rank[a[i-1]] + 1;
        vector<int> result(n);
        for (int i=0;i<n;++i)
            result[i] = rank[arr[i]];
        return result;
    }
};
