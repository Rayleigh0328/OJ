class Solution {
    
    vector<string> words;
    vector<string> unpadded_words;
    string result;
    
    int n;
    bool ans_flag;
    vector<char> a;
    unordered_set<char> leading_set;
    unordered_map<char, int> c_to_d;
    
    void solve(int k, int carry){
        unordered_set<char> varable_set;
        int sum = carry;
        for (string &word : words){
            char ch = word[k];
            if (c_to_d[ch]) sum += c_to_d[ch];
        }
    }
    
    void add_ch(char ch, unordered_set<char> &s){
        if (ch == '#') return; 
        if (s.find(ch) != s.end()) return;
        s.emplace(ch);
        a.push_back(ch);
    }
    
    void decide_order(){
        unordered_set<char> appeared;
        for (int i=n-1; i>=0; --i){
            for (string &word : words) add_ch(word[i], appeared);
            add_ch(result[i], appeared);
        }     
    }
    
    void build_leading_set(){
        for (string &word : words)
            leading_set.emplace(word[0]);
        leading_set.emplace(result[0]);
    }
    
    bool feasible(unordered_map<char, int> &mp){
        // check leading zero
        char ch;
        for (string &word : unpadded_words){
            ch = word[0];
            if (mp.find(ch) != mp.end() && mp[ch] == 0 && word.size() > 1) return false;
        }
        
        int carry = 0;
        int sum = 0;
        for (int i = n-1; i>=0; --i){
            sum = carry;
            for (string &word : words){
                ch = word[i];
                if (mp.find(ch) == mp.end()) return true;
                sum += mp[ch];
            }
            ch = result[i];
            if (mp.find(ch) == mp.end()) return true;
            if (sum % 10 != mp[ch]) return false;
            carry = sum / 10;
        }
        return true;
    }
    
    void solve(int pos, set<int> &available){
        
        if (pos == a.size()) {
            printf("-------------\n");
            for (auto e : c_to_d)
                printf("%c --> %d\n", e.first, e.second);
            printf("-------------\n");
            ans_flag = true;
        }
        if (ans_flag) return;
        
        vector<int> todo;
        for(int digit : available)
            todo.push_back(digit);
        
        for (int digit : todo){
            c_to_d[a[pos]] = digit;
            available.erase(digit);
            if (feasible(c_to_d))
                solve(pos + 1, available);
            c_to_d.erase(a[pos]);
            available.emplace(digit);
        }
    }
    
public:
    bool isSolvable(vector<string>& _words, string _result) {
        
        words = _words;
        unpadded_words = words;
        result = _result;
        n = result.size();
        
        for (string &word : words)
            if (word.size() > result.size()) return false;
        
        build_leading_set();
        
        printf("leading set: ");
        for (char ch : leading_set){
            printf("%c", ch);
        }
        printf("\n");
        
        // padding
        c_to_d['#'] = 0;
        for (string &word : words)
            while (word.size() < n)
                word = '#' + word;
        
        printf("after padding: \n");
        for (string &word : words)
            cout << word << endl;
        cout << result << endl;
        
        // build search order, store in array a
        decide_order();
        
        for (char ch : a) printf("%c", ch);
        printf("\n");
        
        // backtrace
        set<int> available;
        for (int i=0;i<10;++i)
            available.emplace(i);
        ans_flag = false;
        solve(0, available);
        
        return ans_flag;
    }
};
