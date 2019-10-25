class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& a) {
        vector<vector<int>> result;
        sort(a.begin(), a.end());
        do{
            result.push_back(a);
        }while (next_permutation(a.begin(),a.end()));
        return result;
    }
};
