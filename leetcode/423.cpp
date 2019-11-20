class Solution {
    
    vector<string> digit{
        "zero",
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine"
    };
    
    vector<pair<int,char>> order{
        pair<int,char>(0,'z'),
        pair<int,char>(6,'x'),
        pair<int,char>(8,'g'),
        pair<int,char>(3,'h'),
        pair<int,char>(4,'r'),
        pair<int,char>(5,'f'),
        pair<int,char>(7,'v'),
        pair<int,char>(2,'t'),
        pair<int,char>(1,'o'),
        pair<int,char>(9,'i')
    };
    
public:
    string originalDigits(string s) {
        unordered_map<char, int> count;
        for (char ch : s) ++count[ch];
        vector<int>result(10,0);
        for (auto &e : order){
            int target = e.first;
            char key_char = e.second;
            int total = count[key_char];
            result[target] = total;
            for (char ch : digit[target])
                count[ch] -= total;
        }
        string ans;
        for (int i=0;i<10;++i)
            for (int j=0;j<result[i];++j)
                ans.push_back(i+'0');
        return ans;
    }
};
