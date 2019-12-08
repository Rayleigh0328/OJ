class Solution {
    
    vector<int> x_diff{1, -1, 0, 0, 0};
    vector<int> y_diff{0, 0, -1, 1, 0};
    
    unordered_map<string, int> step;
    queue<string> que;
    int n;
    int m;
public:
    int minFlips(vector<vector<int>>& mat) {
        if (mat.empty() || mat[0].empty()) return -1;
        
        // convert matrix into a string as state by connecting each row
        n = mat.size();
        m = mat[0].size();
        string init_state;
        for (int i=0;i<n;++i)
            for (int j=0;j<m;++j)
                init_state.push_back(mat[i][j] + '0');
        
        cout << "init state: " << init_state << endl;
        if (is_target_state(init_state)) return 0;
        
        // BFS
        step[init_state] = 0;
        que.push(init_state);
        while (!que.empty()){
            string from_state = que.front();
            // cout << "process: " << from_state << endl;
            que.pop();
            for (int i=0;i<from_state.size();++i){
                string next_state = flip(from_state, i);
                if (step.find(next_state) == step.end()){
                    step[next_state] = step[from_state] + 1;
                    que.push(next_state);
                    if (is_target_state(next_state)) return step[next_state];
                }
            }
        }
        // if answer can not be found
        return -1;
    }
    
    string flip(const string &state, int pos){
        string result = state;
        int x = pos / m;
        int y = pos % m;
        int next_x, next_y;
        for (int i=0;i<5;++i){
            next_x = x + x_diff[i];
            next_y = y + y_diff[i];
            if (in_board(next_x, next_y)){
                int index = next_x * m + next_y;
                if (result[index] == '0') result[index] = '1';
                else result[index] = '0';
            }
        }
        return result;
    }
    
    bool in_board(int x, int y){
        return (0 <= x && x < n && 0 <= y && y < m);
    }   
    
    bool is_target_state(const string& state){
        for (char ch : state)
            if (ch != '0') return false;
        return true;
    }
};
