class Solution {  
    
    bool check(set<int>&s, int round){
        return (s.empty() || *s.begin() == round + 1);
    }
    
public:
    int numTimesAllBlue(vector<int>& pos) {
        set<int> s;
        for (auto x : pos) s.emplace(x);
        int result = 0;
        for (int i=0;i<pos.size();++i){
            s.erase(pos[i]);
            if (check(s,i+1)) ++result;
        }
        return result;
    }
};
