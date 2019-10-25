bool cmp(const string& a, const string &b){
    string x = a;
    string y = b;
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    return x < y;
}

class Solution {
      
public:
    vector<vector<string>> groupAnagrams(vector<string>& a) {
        int n = a.size();
        sort(a.begin(), a.end(), cmp);
        vector<vector<string>> result;
        int i, next;
        for (i=0;i<n;){
            next = i+1;
            while (next < n && !cmp(a[next], a[i]) && !cmp(a[i], a[next])) ++next;
            vector<string> row;
            for (int j=i;j<next;++j) row.push_back(a[j]);
            result.push_back(row);
            i=next;
        }
        return result;
    }
};
