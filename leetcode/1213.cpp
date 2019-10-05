class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        unordered_set<int> s1;
        for (auto x : arr1) s1.emplace(x);
        
        unordered_set<int> s2;
        for (auto x : arr2) s2.emplace(x);
        
        vector<int> ans;
        for (auto x : arr3)
            if (s1.find(x)!=s1.end()&&s2.find(x)!=s2.end())
                ans.push_back(x);
        return ans;
    }
};
