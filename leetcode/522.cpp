class Solution {
    
    bool check(const string &p, const string &s){
        int pos = 0;
        for (int i=0;i<p.size();++i){
            char ch = p[i];
            while (pos<s.size() && s[pos] != ch) ++pos;
            if (i == p.size()-1 && pos < s.size()) return true;
            ++pos;
        }
        return false;
    }
    
public:
    int findLUSlength(vector<string>& a) {
        sort(a.begin(), a.end(), [](const string &x, const string &y){return x.size() > y.size();});
        for (int i=0;i<a.size();++i){
            bool flag = false;
            for (int j=0;j<a.size();++j)
                if (j != i && check(a[i], a[j])) {
                    flag = true;
                    break;
                }
            if (!flag) return a[i].size();
        }
        return -1;
    }
};
