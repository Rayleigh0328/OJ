class Solution {
    
    map<string, string> mp{
        {"Jan","1"}, 
        {"Feb","2"}, 
        {"Mar","3"}, 
        {"Apr","4"}, 
        {"May","5"}, 
        {"Jun","6"}, 
        {"Jul","7"}, 
        {"Aug","8"}, 
        {"Sep","9"}, 
        {"Oct","10"}, 
        {"Nov","11"}, 
        {"Dec","12"}
    };
    
    bool is_digit(char ch){
        return '0' <= ch && ch <= '9';
    }
    
public:
    string reformatDate(string date) {
        int pos = date.find(" ", 0);
        string day_str = date.substr(0, pos);
        while (!is_digit(day_str.back())) day_str.pop_back();
        if (day_str.size() == 1) day_str = '0' + day_str;
        cout << "$"<< day_str << "$" << endl;
        
        int next_pos = date.find(" ",pos+1);
        string month_str = date.substr(pos+1, next_pos-pos-1);
        pos = next_pos;
        month_str = mp[month_str];
        if (month_str.size() == 1) month_str = '0' + month_str;
        cout << "$"<< month_str << "$" << endl;
        
        string year_str = date.substr(pos+1);
        cout << "$"<< year_str << "$" << endl;
        
        string result = year_str +'-'+ month_str +'-'+ day_str;
        cout << result << endl;
        return result;
    }
};
