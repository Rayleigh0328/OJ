class Solution {

    int n;
    vector<int> parent;
    
    void union_set(int x, int y){
        parent[find_set(x)] = find_set(y);
    }

    int find_set(int x){
        if (x == parent[x]) return x;
        return (parent[x] = find_set(parent[x]));
    }

public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        n = s.length();
        parent = vector<int>(n);
        // construct union set
        for (int i=0;i<s.size();++i) parent[i] = i;
        for (auto e : pairs) union_set(e[0], e[1]);

//        for (int i=0; i<n;++i) cout << find_set(i) << " "; cout << endl;
        // construct label to multiset
        vector<multiset<char>> set_list(n); 
        for (int i=0;i<n;++i){
            set_list[find_set(i)].emplace(s[i]);
        }

        string ans = "";
        for (int i=0; i<n;++i){
            multiset<char> &char_set = set_list[find_set(i)];
            auto it = char_set.begin();
            ans += *it;
            char_set.erase(it);
        } 
        return ans;
    }
};
