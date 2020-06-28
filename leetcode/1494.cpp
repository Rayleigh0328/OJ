class Solution {
    const int inf = (1<<28);
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) {
        vector<int> pre(n,0);
        for (auto &e : dependencies)
            pre[e[1]-1] |= (1 << (e[0] - 1)); 
        int max_state = (1<<n);
        vector<int> f(max_state, inf);
        f[0] = 0;
        for (int state=0;state<max_state;++state){
            int feasible = 0;
            for (int i=0;i<n;++i)
                if ((pre[i] & state) == pre[i]) feasible += (1<<i);
            feasible = (feasible & ~state);
            for (int todo = feasible; todo>0; todo = ((todo-1) & feasible) ){
                if (__builtin_popcount(todo) <= k) f[state | todo] = min(f[state|todo], f[state] + 1);
            }
        }
        return f[max_state-1];
    }
};
