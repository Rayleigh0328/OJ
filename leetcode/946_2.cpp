class Solution {
public:
    bool validateStackSequences(vector<int>& a, vector<int>& b) {
        int n = a.size();
        if (b.size() != n) return false;
        int p1 = 0, p2 = 0;
        stack<int> st;
        while (p1 < n && p2 < n){
            while ((st.empty() || st.top() != b[p2]) && p1 < n) st.push(a[p1++]);
            if(p1 == n && st.top() != b[p2]) return false;
            while (p2 < n && !st.empty() && b[p2] == st.top()){
                st.pop();
                ++p2;
            }
        }
        return (p1 == n && p2 == n);
    }
};
