class Solution {
public:
    string frequencySort(string s) {
        vector<int> count(256,0);
        for (char ch : s) ++count[ch];
        sort(s.begin(), s.end(), [&count](char x, char y){
            if (count[x] > count[y]) return true;
            if (count[x] < count[y]) return false;
            if (x < y) return true;
            return false;
        });
        return s;
    }
};
