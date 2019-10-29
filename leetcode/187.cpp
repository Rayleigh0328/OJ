class Solution {
    const int base = 4;
    const int len = 10;
    
    unordered_map<char,int> c_to_i{
        {'A',0},
        {'C',1},
        {'G',2},
        {'T',3}
    };
    
    unordered_map<int, char> i_to_c{
        {0,'A'},
        {1,'C'},
        {2,'G'},
        {3,'T'}
    };
    
    string decode(long long code){
        string result;
        for (int i=0;i<len;++i){
            result = i_to_c[code % base] + result;
            code = code / base;
        }
        return result;
    }
    
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        unordered_map<long long, int> count; 
        
        if (s.length() < len) return result;
        
        long long h = 1ll;
        for (int i=0;i<len-1;++i) h = h * base;
        
        long long current = 0ll;
        for (int i=0;i<len;++i)
            current = current * base + c_to_i[s[i]];
        ++count[current];
        
        for (int i=1;i+len-1<s.length();++i){
            current = (current - c_to_i[s[i-1]] * h) * base + c_to_i[s[i+len-1]];
            ++count[current];
        }
        for (auto &e : count)
            if (e.second > 1) 
                result.push_back(decode(e.first));
        return result;
    }
};
