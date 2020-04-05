class Solution {
    
    void add_one(vector<int> &a){
        int pos = a.size()-1;
        int c = 1;
        while (pos >= 0 && c != 0){
            a[pos] += c;
            if (a[pos] == 2) {
                a[pos] = 0;
                c = 1;
            }
            else {
                break;
            }
            --pos;
        }
        if (pos == -1){
            a.insert(a.begin(), 1);
        }
    }
    
    void divide_two(vector<int>&a){
        a.pop_back();
    }
    
public:
    int numSteps(string s) {
        vector<int> a;
        for (int i=0;i<s.size();++i) a.push_back(s[i]-'0');
        
        int result = 0;
        while (a.size() > 1){
            if (a.back() == 1) add_one(a);
            else divide_two(a);
            // for (auto x : a) cout << x; cout << endl;
            ++result;
        }
        return result;
    }
};
