string get_key(const string& s){
    string t(s);
    sort(t.begin(),t.end());
    return t;
}

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& a) {
        unordered_map<string, vector<string>> h;
        for (int i=0;i<a.size();++i)
            h[get_key(a[i])].push_back(a[i]);
        vector<vector<string>> result;
        for (auto &x : h)
            result.push_back(x.second);
        return result;
    }
};
