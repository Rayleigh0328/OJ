class Solution {
    
    string concat_string(const vector<string> &v){
        string result = "";
        for (string s : v){
            result += s;
        }
        return result;
    }
    
    int solve(const vector<string>& words, int max_width, int s, vector<string>& ans){
        vector<string> line;
        line.push_back(words[s]);
        int sum_len = words[s].length();
        
        int t = s + 1;
        while (t < words.size() && 1 + words[t].length() + sum_len <= max_width){
            line.push_back(" ");
            line.push_back(words[t]);
            sum_len += 1 + words[t].length();
            ++t;
        }
        
        // case 1
        if (t == words.size()) {
            string tmp = concat_string(line);
            while (tmp.length() < max_width) tmp += " ";
            ans.push_back(tmp);
            return t;
        }
        
        // case 2
        if (line.size() == 1){
            // special case, line only have 1 word
            if (line[0].length() == max_width) {
                ans.push_back(line[0]);
                return t;
            }
            else{
                line.push_back(" ");
                sum_len += 1;
            }
        }
        
        // padding 
        int to_pad = max_width - sum_len;
        int pos = 1;
        while(to_pad > 0){
            line[pos] = line[pos] + " ";
            --to_pad;
            pos = pos + 2;
            if (pos >= line.size()) pos = 1;
        }
        
        ans.push_back(concat_string(line));
        return t;
    }
    
public:
    vector<string> fullJustify(vector<string>& words, int max_width) {
        // simulation 
        // start from index s in words
        // case 1: words[s], words[s+1], ... words[n] can be put in one line
        // case 2: words[s]...words[t] should be put in one line
        vector<string> ans;
        int end_pos = solve(words, max_width, 0, ans);
        while (end_pos != words.size()){
            end_pos = solve(words, max_width, end_pos, ans);
        }
        return ans;
    }
};
