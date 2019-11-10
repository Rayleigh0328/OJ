class Solution {
    unordered_map<char,int> limit;
    int n;
    
    int solve(int state, const vector<string>& words, const vector<int>& score){
        unordered_map<char,int> count;
        for (int i=0;i<n;++i){
            if (state & (1<<i)){
                // words[i] is selected
                for (char ch : words[i]) ++count[ch];
            }
        }
        
        int result = 0;
        for (auto e : count){
            if (e.second > limit[e.first]) return 0;
            else result += score[e.first-'a'] * e.second;
        }
        return result;
    }
    
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        
        n = words.size();
        
        // create limit map
        for (char ch : letters) ++limit[ch];
        
        int ans = 0;
        for (int state = 1; state < (1<<n); ++state){
            int tmp = solve(state, words, score);
            if (tmp > ans) ans = tmp;
        }
        
        return ans;
    }
};
