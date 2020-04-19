class Solution {
    unordered_set<char> feasible{'c','r','o','a','k'};
    unordered_map<char, int> count;
    
    bool check(){
        if (count['r'] > count['c']) return false;
        if (count['o'] > count['r']) return false;
        if (count['a'] > count['o']) return false;
        if (count['k'] > count['a']) return false;
        return true;
    }
    
public:
    int minNumberOfFrogs(string s) {
        
        char ch;
        int result = 0;
        for (int i=0;i<s.size();++i){
            ch = s[i];
            if (feasible.find(ch) == feasible.end()) return -1;
            ++count[ch];
            if (!check()) return -1;
            if (ch == 'k'){
                for (char ch : feasible) --count[ch];
            }
            if (ch == 'c')
                result = max(result, count[ch]);
        }
        for(char ch : feasible)
            if (count[ch] != 0) return -1;
        return result;
    }
};
