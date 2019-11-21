typedef pair<char,int> Run;

class Solution {
public:
    int compress(vector<char>& chars) {
        vector<Run> a;
        for (char ch : chars){
            if(a.empty() || ch != a.back().first) a.push_back(Run(ch, 1));
            else ++a.back().second;
        }
        chars.clear();
        for (auto &r : a){
            chars.push_back(r.first);
            if (r.second == 1) continue;
            string st = to_string(r.second);
            for (char ch : st)
                chars.push_back(ch);
        }
        return chars.size();
    }
};
