class Solution {
public:
    string sortString(string s) {
        vector<int> count(26,0);
        for (int i=0;i<s.size();++i) ++count[s[i]-'a'];
        string result;
        bool inc_flag = true;
        while (result.size() < s.size()){
            if (inc_flag){
                for (int i=0;i<26;++i)
                    if (count[i] > 0){
                        --count[i];
                        result += (char)(i + 'a');
                    }
            }
            else {
                for (int i=25;i>=0;--i)
                    if (count[i] > 0){
                        --count[i];
                        result += (char)(i + 'a');
                    }
            }
            inc_flag = !inc_flag;
        }
        return result;
    }
};
