class Solution {
    
    int n;
    vector<int> status;
    vector<int> candies;
    vector<vector<int>> keys;
    vector<vector<int>> contained_boxes;
 
public:
    int maxCandies(vector<int>& _status, vector<int>& _candies, vector<vector<int>>& _keys, vector<vector<int>>& _containedBoxes, vector<int>& initialBoxes) {
        status = _status;
        candies = _candies;
        keys = _keys;
        contained_boxes = _containedBoxes;
        n = status.size();
        
        // build init state
        string state = string(n, 'U');
        for (auto ind : initialBoxes)
            state[ind] = status[ind] + '0';
        // cout << "init state: " << state << endl;
        while (true){
            string next_state = get_next(state);
            // cout << "next state: " << next_state << endl;
            if (state.compare(next_state) == 0) break;
            state = next_state;
        }
        return count_candies(state);
    }

private:
    
    string get_next(const string &s){
        string result = s;
        unordered_set<int> key_set;
        for (int i=0;i<s.size();++i){
            if (s[i] == '1'){
                for (auto x : keys[i]) key_set.emplace(x);
                for (auto x : contained_boxes[i])
                    if (result[x] == 'U') result[x] = '0' + status[x]; 
            }
        }
        for (int i=0;i<n;++i)
            if (result[i] == '0' && key_set.find(i) != key_set.end())
                result[i] = '1';
        return result;
    }
    
    int count_candies(const string &s){
        int result = 0;
        for (int i=0;i<s.size();++i)
            if (s[i] == '1') result += candies[i];
        return result;
    }
};
