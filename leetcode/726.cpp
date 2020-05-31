class Solution {
    typedef map<string,int> MapType; 
public:
    string countOfAtoms(string formula) {
        int pos = 0;
        MapType mp = parse_formula(formula, pos);
        return convert_to_string(mp);
    }
private:
    void merge(MapType &result_map, MapType to_merge){ for (auto &e : to_merge) result_map[e.first] += e.second; }
    void multiply(MapType &result_map, int factor){ for (auto &e : result_map) e.second *= factor; }
    bool is_digit(char ch){ return ('0' <= ch && ch <= '9'); }
    bool is_uppercase(char ch){ return ('A' <= ch && ch <= 'Z'); }
    bool is_lowercase(char ch){ return ('a' <= ch && ch <= 'z'); }
    
    MapType parse_formula(string &s, int &pos){
        MapType result;
        while (pos < s.size() && s[pos] != ')'){
            MapType tmp = parse_unit(s, pos);
            merge(result, tmp);
        }
        return result;
    }
    
    MapType parse_unit(string &s, int &pos){
        MapType result;
        if (s[pos] == '(') {
            result = parse_formula(s,++pos);
            ++pos;
        }
        else {
            result = parse_element(s, pos);
        }
        int repeat = 1;
        if (is_digit(s[pos])) repeat = parse_number(s, pos);
        multiply(result, repeat);
        return result;
    }
    
    MapType parse_element(string &s, int &pos){
        string element;
        element += s[pos++];
        while (is_lowercase(s[pos]))
            element += s[pos++];
        return {{element, 1}};
    }
    
    int parse_number(string &s, int &pos){
        int result = 0;
        while (is_digit(s[pos])){
            result = result * 10 + s[pos] - '0';
            ++pos;
        }
        return result;
    }
    
    string convert_to_string(MapType &mp){
        string result;
        for (auto &e : mp)
            result += e.first + (e.second > 1 ? to_string(e.second) : "");
        return result;
    }
};
