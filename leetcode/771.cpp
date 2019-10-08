class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> j_set;
        for (int i=0;i<J.length();++i) j_set.emplace(J[i]);
        int ans = 0;
        for (int i=0;i<S.length();++i)
            if (j_set.find(S[i]) != j_set.end()) ++ans;
        return ans;
    }
};
