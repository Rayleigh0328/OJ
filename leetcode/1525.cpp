class Solution {
    const int inf = (1<<30);
    
    unordered_map<char, int> start_pos, end_pos;
    
    bool check(int pos){
        int left=0, right=0;
        for (char ch = 'a'; ch <= 'z'; ++ch){
            if (end_pos[ch] <= pos) ++left;
            if (pos < start_pos[ch]) ++right;
        }
        return (left == right);
    }
    
public:
    int numSplits(string s) {
        for (char ch = 'a'; ch <= 'z'; ++ch){
            start_pos[ch] = -inf;
            end_pos[ch] = inf;
        }
        const int n = s.size();
        for (int i=0;i<n;++i) end_pos[s[i]] = i;
        for (int i=n-1;i>=0;--i) start_pos[s[i]] = i;
        
        int result = 0;
        for (int i=0;i<n;++i)
            if (check(i)) ++result;
        return result;
    }
};
