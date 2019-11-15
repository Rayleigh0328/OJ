class Solution {
    
    vector<int> get_ans(int s){
        // printf("get_ans: %d\n", s);
        vector<int> result(8,0);
        for (int i=0;i<8;++i)
            if (s & (1<<i))
                result[i] = 1;
        return result;
    }
    
    int get_next_state(int s){
        int result = 0;
        
        for (int i=1;i<7;++i){
            int x = ((s & (1<<(i-1))) > 0);
            int y = ((s & (1<<(i+1))) > 0);
            if (!(x^y)) result += (1 << i);
        }
        
        return result;
    }
    
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        
        // construct init state
        int init_state = 0;
        for (int i=0;i<8;++i)
            init_state += cells[i] * (1 << i);
        // printf("init: %d\n", init_state);
        // day[i] is the state of ith day
        vector<int> day={init_state};
        unordered_map<int, int> state_to_day{{init_state,0}};
        int loop_index;
        while (true){
            int next_state = get_next_state(day.back());
            // printf("next: %d\n", next_state);
            if (state_to_day.find(next_state) != state_to_day.end()){
                // find loop
                loop_index = state_to_day[next_state];
                break;
            }
            else{
                state_to_day.emplace(next_state, day.size());
                day.push_back(next_state);
            }
        }
        
        if (N <= loop_index) return get_ans(day[N]);
        else return get_ans(day[loop_index + (N - loop_index) % (day.size() - loop_index)]);
    }
};
