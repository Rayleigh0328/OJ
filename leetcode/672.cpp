class Solution {
    
    bool check(int state, int op_count){
        int count = 0;
        for (int i=1;i<16;i*=2)
            if (state & i) ++count;
        if (count > op_count) return false;
        if ((op_count - count) & 1) return false;
        return true;
    }
    
    char flip(char x){
        if (x == 'u') return 'd';
        else return 'u';
    }
    
    string perform(int state, int len){
        string result(len, 'u');
        if (state & 1){
            for (int i=0;i<len;++i)
                result[i] = flip(result[i]);
        }
        if (state & 2){
            for (int i=1;i<len;i+=2)
                result[i] = flip(result[i]);
        }
        if (state & 4){
            for (int i=0;i<len;i+=2)
                result[i] = flip(result[i]);
        }
        if (state & 8){
            for (int i=0;i<len;i+=3)
                result[i] = flip(result[i]);
        }
        return result;
    }
    
public:
    int flipLights(int n, int m) {
        unordered_set<string> result;
        for (int i=0;i<16;++i)
            if (check(i, m)) result.emplace(perform(i,n));
        return result.size();
    }
};
