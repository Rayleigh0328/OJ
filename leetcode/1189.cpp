class Solution {
public:
    int maxNumberOfBalloons(string st) {
        vector<int> count(256,0);
        for (int i=0; i<st.length();++i)
            ++count[st[i]];
        count['l']/=2;
        count['o']/=2;
        int ans = st.length();
        ans = min(ans, count['b']);
        ans = min(ans, count['a']);
        ans = min(ans, count['l']);
        ans = min(ans, count['o']);
        ans = min(ans, count['n']);
        return ans;
    }
};
