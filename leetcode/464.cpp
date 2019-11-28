class Solution {

    unordered_map<int, int> num_to_index;
    unordered_map<int, int> index_to_num;
    int f[(1<<21)];
    int target;
    
    int low_bit(int x){
        return (x & -x);
    }
    
    int solve(int sum, int state){
        if (state == 0) return f[state] = -1;
        if (f[state] != 0) return f[state];
        if (sum < target && sum + num_to_index[low_bit(state)] >= target) return (f[state] = 1);
        
        int cur = state, tmp;
        while (cur != 0){
            tmp = low_bit(cur);
            if (solve(sum+num_to_index[tmp], state-tmp) == -1) return (f[state] = 1);
            cur -= tmp;
        }
        return (f[state] = -1);
    }
    
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        
        if (desiredTotal <= maxChoosableInteger) return true;
        int sum = 0;
        for (int i=1;i<=maxChoosableInteger;++i) sum+=i;
        if (sum < desiredTotal) return false;
        
        target = desiredTotal;
        for (int i=0;i<20;++i){
            num_to_index.emplace((1<<(19-i)), i+1);
            index_to_num.emplace(i+1, 1<<(19-i));
        }
        memset(f, 0, sizeof(f));
        int init_state=0;
        for (int i=1;i<=maxChoosableInteger;++i)
            init_state += index_to_num[i];
        return (solve(0, init_state) > 0);
    }
};
