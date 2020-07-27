class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        vector<int> a;
        for (auto x : target) a.push_back(x);
        a.push_back(0);
        
        vector<int> st;
        int result = 0;
        for (auto x : a){
            if (!st.empty() && st.back() >= x) {
                result += st.back() - x;
                while (!st.empty() && st.back() >= x) st.pop_back();
            }
            st.push_back(x);
        }
        return result;
    }
};
