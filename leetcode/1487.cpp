class Solution {
    
    unordered_map<string, set<int>> existingNames;
    set<string> resultSet;
    
    int suffix_pos(const string &s){
        if (s.back() != ')') return -1;
        int index = s.size() - 2;
        while (index>=0 && '0'<=s[index] && s[index]<='9') --index;
        if (index < 0) return -1;
        return (s[index] == '('?index:-1);
    }
    
    string strip_suffix(const string &s, int pos){
        return s.substr(0,pos);
    }
    
    int get_serial(const string &s, int pos){
        string result = s.substr(pos + 1);
        result.pop_back();
        return stoi(result);
    }
    
    string process(string &input){
        int pos = suffix_pos(input);
        string s = input;
        if (pos != -1) s = strip_suffix(input, pos);
        int serial = -1;
        if (pos != -1) serial = get_serial(input, pos);
        // cout << "s: " << s << ", " << "serial: " << serial << endl; 
        
        if (serial == 0) {
            existingNames[input].emplace(0);
            return input;
        }
        
        if (resultSet.find(input) == resultSet.end()) {
            if (serial != -1) {
                if (existingNames[s].empty()) existingNames[s].emplace(0);
                existingNames[s].emplace(serial);
            }
            return input;
        }
        
        set<int> &indexSet = existingNames[input];
        int index = *indexSet.begin();
        while (indexSet.find(index+1) != indexSet.end()){
            indexSet.erase(indexSet.begin());
            ++index;
        }
        indexSet.emplace(++index);
        return input + "(" + to_string(index) + ")";
    }
    
public:
    vector<string> getFolderNames(vector<string>& names) {
        vector<string> result;
        for (auto &s : names){
            string t = process(s);
            resultSet.emplace(t);
            result.push_back(t);
        }
        return result;
    }
};
