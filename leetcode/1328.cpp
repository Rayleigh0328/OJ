class Solution {
public:
    string breakPalindrome(string st) {
        if (st.size() <= 1) return "";
        
        string result = st;
        string mid = "";
        if (result.size() & 1){
            result.erase((result.size()-1)/2, 1);
            mid.push_back(st[(st.size()-1)/2]);
        }
        
        cout << "mid: " << mid << endl;
        // not all a
        for (int i=0;i<result.size();++i)
            if (result[i] != 'a') {
                result[i] = 'a';
                if (st.size() & 1) result.insert(result.size()/2, mid);
                return result;
            }
        
        // all a
        result.back() = 'b';
        if (st.size() & 1) result.insert(result.size()/2, mid);
        return result;
    }
};
