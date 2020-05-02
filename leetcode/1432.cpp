class Solution {
    
    int replace(int num, int x, int y){
        string s = to_string(num);
        for (int i=0;i<s.size();++i)
            if (s[i] == '0' + x) s[i] = '0' + y;
        
        if (s[0] == '0') return 0;
        return stoi(s);
    }
    
public:
    int maxDiff(int num) {
        vector<int> cand;
        int tmp;
        for (int i=0;i<=9;++i)
            for (int j=0;j<=9;++j){
                tmp = replace(num,i,j);
                if (tmp != 0) cand.push_back(tmp);
            }
        sort(cand.begin(), cand.end());
        return cand.back() - cand[0];
    }
};
