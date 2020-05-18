class Solution {
public:
    string arrangeWords(string text) {
        vector<string> a;
        int pos = -1, next;
        while ((next = text.find(" ", pos+1)) != string::npos){
            a.push_back(text.substr(pos+1,next-pos-1));
            pos = next;
        }
        a.push_back(text.substr(pos+1));
        // for (auto x : a) cout << x << endl;
        
        stable_sort(a.begin(), a.end(), [](const string &x, const string &y){
            return x.size() < y.size();
        });
        
        string result;
        for (auto x : a) result += x + ' ';
        result.pop_back();
       
        for (int i=0;i<result.size();++i)
            if ('A' <= result[i] && result[i] <= 'Z') result[i] = result[i] - 'A' + 'a';
        result[0] = result[0] - 'a' + 'A';
        return result;
    }
};
