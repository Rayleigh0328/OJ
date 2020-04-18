class Solution {
    
    int n;
    
    string convert(int state){
        int digit;
        string result="";
        for (int i=0;i<n;++i){
            digit = state % 3;
            state /= 3;
            result.push_back('a'+digit);
        }
        reverse(result.begin(), result.end());
        return result;
    }
    
    bool check(int state){
        int prev = -1;
        int cur;
        for (int i=0;i<n;++i){
            cur = state % 3;
            state /= 3;
            if (cur == prev) return false;
            prev = cur;
        }
        return true;
    }
    
public:
    string getHappyString(int nn, int k) {
        n = nn;
        int max_state = 1;
        for (int i=0;i<n;++i) max_state *= 3;
        
        // printf("max_state: %d\n", max_state);
        
        vector<int> a;
        for (int state = 0; state < max_state; ++state)
            if (check(state)) {
                a.push_back(state);
                // cout << convert(state) << endl;
            }
        
        if (k>a.size()) return "";
        return convert(a[k-1]);
    }
};
