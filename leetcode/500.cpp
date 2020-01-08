class Solution {
    
    unordered_map<char, int> row{
        {'q',1},{'w',1},{'e',1},{'r',1},{'t',1},{'y',1},{'u',1},{'i',1},{'o',1},{'p',1},
        {'a',2},{'s',2},{'d',2},{'f',2},{'g',2},{'h',2},{'j',2},{'k',2},{'l',2},
        {'z',3},{'x',3},{'c',3},{'v',3},{'b',3},{'n',3},{'m',3}
    };
    
    
    char to_lower(char x){
        if ('A' <= x && x <='Z') return x - 'A' + 'a';
        return x;
    }
    
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> result;
        for (auto &word : words){
            unordered_set<int> row_set;
            for (int i=0;i<word.size();++i)
                row_set.emplace(row[to_lower(word[i])]);
            if (row_set.size() == 1)
                result.push_back(word);
        }
        return result;
    }
};
