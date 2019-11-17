class Solution {
    
    const int inf = (1<<30);
    
    vector<int> x_diff{0,0,-1,1};
    vector<int> y_diff{1,-1,0,0};
    
    int n,m;
    int ans;
    int target_row;
    int target_col;
    queue<string> que;
    unordered_map<string, int> push_count;
    
    string convert_grid_to_string(const vector<vector<char>> &grid){
        string result;
        for (int i=0;i<n;++i)
            for (int j=0;j<m;++j){
                // cout << grid[i][j] << endl;
                if (grid[i][j]=='T'){
                    result += '.';
                    target_row = i;
                    target_col = j;
                }
                else result += grid[i][j];
            }
        // cout << "convert grid to string: " << result << endl;
        return result;
    }
    
    bool is_answer(const string& state){
        int pos = state.find('B');
        int row = pos / m;
        int col = pos % m;
        return (row == target_row && col == target_col);
    }
    
    char get_char(const string &st, int row, int col){
        return st[row * m + col];
    }
    
    int encode(int row, int col){
        return row * m + col;
    }
    
    bool in_board(int row, int col){
        return (0 <= row && row < n && 0 <= col && col < m); 
    }
    
    void move(string state, int direction){
        // cout << "old_state: " << state << endl;
        int pos = state.find('S');
        int x = pos / m;
        int y = pos % m;
        int next_x = x + x_diff[direction];
        int next_y = y + y_diff[direction];
        
        // invalid move
        if (!in_board(next_x, next_y) || get_char(state, next_x, next_y) == '#') return;
        
        if (get_char(state, next_x, next_y) == 'B'){
            // this move is a push
            int next_box_x = next_x + x_diff[direction];
            int next_box_y = next_y + y_diff[direction];
            
            //check invalid push
            if (!in_board(next_box_x, next_box_y) || get_char(state, next_box_x, next_box_y) == '#') return;
            
            int tot_p = push_count[state] + 1; 
            state[encode(x,y)] = '.';
            state[encode(next_x, next_y)] = 'S';
            state[encode(next_box_x, next_box_y)] = 'B';
            
            // cout << "new_state" << state << endl;
            if (push_count.find(state) == push_count.end() || push_count[state] > tot_p){
                if (is_answer(state)) ans = min(ans, tot_p);
                push_count[state] = tot_p;
                que.push(state);
            }
        }
        else {
            // this move is not a push
            int tot_p = push_count[state];
            state[encode(x,y)] = '.';
            state[encode(next_x, next_y)] = 'S';
            // cout << "new_state" << state << endl;
            if (push_count.find(state) == push_count.end() || push_count[state] > tot_p){
                push_count[state] = tot_p;
                que.push(state);
            }
        }
    }
    
public:
    int minPushBox(vector<vector<char>>& grid) {
        
        if (grid.empty() || grid[0].empty()) return -1;
        n = grid.size();
        m = grid[0].size();
        ans = inf;
        
        string state = convert_grid_to_string(grid);
        if (is_answer(state)) return 0;
        
        que.push(state);
        push_count.emplace(state,0);
        
        while (!que.empty()){
            // cout << "process: " << que.front() << endl;
            string prev_state = que.front();
            que.pop();
            for (int i=0;i<4;++i){
                move(prev_state, i);
            }
        }
        
        if (ans == inf) return -1;
        else return ans;
    }
};
