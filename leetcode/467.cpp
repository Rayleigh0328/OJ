class Solution {

    unordered_map<char, int> max_length;
    
    bool is_consecutive(char c1, char c2){
        return ((c1 - 'a' + 1) % 26 == (c2 -'a') % 26);
    }
    
    void update_max_length(const string &st, int p1, int p2){
        for (int i=p1; i<p2; ++i)
            max_length[st[i]] = max(max_length[st[i]], p2-i);
    }

    int get_answer(){
        int result = 0;
        for (char ch = 'a'; ch <= 'z'; ++ch)
            result += max_length[ch];
        return result;
    }
    
public:
    int findSubstringInWraproundString(string s) {
        int p1=0, p2;
        int ans = 0;
        while (p1 < s.size()){
            p2 = p1 + 1;
            while (p2 < s.size() && is_consecutive(s[p2-1],s[p2])) ++p2;
            update_max_length(s, p1, p2);
            p1 = p2;
        }
        return get_answer();
    }
};
