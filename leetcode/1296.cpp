class Solution {
    map<int, int> mp;
public:
    bool isPossibleDivide(vector<int>& a, int k) {
        for (auto x : a) ++mp[x];
        while (!mp.empty()){
            int start = mp.begin() -> first;
            for (int i=0;i<k;++i){
                int cur = start+i;
                if (mp.find(cur) == mp.end()) return false;
                if (--mp[cur] == 0) mp.erase(cur);
            }
        }
        return true;
    }
};
