class Solution {
    vector<vector<int>> f;
    vector<int> seat_map;
    int n, m;
    
    bool check(int prev, int cur, int available_seat){
        if ((cur & available_seat) != 0) return false;
        if ((cur & (cur << 1)) != 0) return false;
        if ((cur & (cur >> 1)) != 0) return false;
        if ((prev & (cur << 1)) != 0) return false;
        if ((prev & (cur >> 1)) != 0) return false;
        return true;
    }
    
    int count(int x){
        int result = 0;
        for (int i=0;i<m;++i)
            if ((x & (1<<i)) > 0) ++result;
        return result;
    }
    
public:
    int maxStudents(vector<vector<char>>& seats) {
        n = seats.size();
        if (n == 0) return 0;
        m = seats[0].size();
        if (m == 0) return 0;
        
        int mask = (1<<m);
        f = vector<vector<int>>(n, vector<int>(mask, 0));
        
        seat_map = vector(n, 0);
        for (int i=0;i<n;++i)
            for (int j=0;j<m;++j)
                if (seats[i][j] == '#')
                    seat_map[i] += (1<<j);
        
        for (int state = 0; state < mask; ++state)
            if (check(0, state, seat_map[0])) f[0][state] = count(state);
        for (int i=1;i<n;++i)
            for (int prev_state = 0; prev_state < mask; ++prev_state)
                for (int cur_state = 0; cur_state < mask; ++cur_state)
                    if (check(prev_state, cur_state, seat_map[i])) f[i][cur_state] = max(f[i][cur_state], f[i-1][prev_state] + count(cur_state));
        
        int result = 0;
        for (int state = 0; state < mask; ++state)
            result = max(result, f[n-1][state]);
        return result;
    }
};
