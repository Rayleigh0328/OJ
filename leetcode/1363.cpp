class Solution {
    vector<multiset<int>> rem;
    
    string construct_ans(vector<multiset<int>>&rem){
        multiset<int> ms;
        for (int i=0;i<3;++i)
            for (auto x : rem[i])
                ms.emplace(x);
        string st;
        for (auto x : ms)
            st.append(1, x + '0');
        while (st.size() > 1 && st.back() == '0') st.pop_back();
        reverse(st.begin(), st.end());
        return st;
    }
    
public:
    string largestMultipleOfThree(vector<int>& digits) {
        rem = vector<multiset<int>>(3);
        for (auto x : digits)
            rem[x % 3].emplace(x);
        int sum = 0;
        for (auto x : digits) sum += x;
        if (sum % 3 == 0) return construct_ans(rem);
        else if (sum % 3 == 1) {
            
            if (rem[1].size() > 0){
                rem[1].erase(rem[1].begin());
            }
            else {
                    rem[2].erase(rem[2].begin());
                    rem[2].erase(rem[2].begin());
                }
            
            return construct_ans(rem);
            
        }
        else {
            
            if (rem[2].size()>0){
                rem[2].erase(rem[2].begin());
            }
            else {
                rem[1].erase(rem[1].begin());
                rem[1].erase(rem[1].begin());
            }
            return construct_ans(rem);
        }
    }
};
