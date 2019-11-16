class DisjointSet{
private:
    int n;
    vector<int> leader;
    vector<int> weight;

public:
    DisjointSet(int size=0):
        n(size)
    {
        leader = vector<int>(n);
        weight = vector<int>(n);
        for (int i=0;i<n;++i) {
            leader[i] = i;
            weight[i] = 1;
        }
    }
    
    int find_set(int k){
        if (leader[k] == k) return k;
        leader[k] = find_set(leader[k]);
        weight[k] = weight[leader[k]];
        return leader[k];
    }
    
    void union_set(int x, int y){
        if (find_set(x) == find_set(y)) return;
        // always attach smaller weight to larger weight
        // make sure the set of x have larger weight
        if (weight[find_set(x)] < weight[find_set(y)]){ 
            union_set(y,x);
        } 
        else{
            weight[find_set(x)] = weight[find_set(x)] + weight[find_set(y)];
            leader[find_set(y)] = find_set(x);
        }
    }
    
    int count_set(){
        unordered_set<int> label_set;
        for (int i=0;i<n;++i)
            label_set.insert(find_set(i));
        return label_set.size();
    }

    int get_weight(int k){
        return weight[find_set(k)];
    }
    
    void print_leader(){
        for (int i=0;i<n;++i){
            printf("%d --> %d\n", i, find_set(i));
        }
    }
};


class Solution {
    vector<string> result;
    unordered_map<string, int> string_to_label;
    int count_label;
    DisjointSet ds;
    
    void solve(string state, int pos){
        // cout << "solve: " << state << " with start pos " << pos << endl;
        if (pos >= state.length()) {
            // cout << "find answer: " << state << endl;
            result.push_back(state);
            return;
        }
        
        int next_pos = state.find(' ', pos);
        if (next_pos == string::npos) next_pos = state.length();
        
        string word = state.substr(pos, next_pos-pos);
        if (string_to_label.find(word) == string_to_label.end()) {
            solve(state, next_pos+1); 
        }
        else {
            string prev = state.substr(0, pos);
            string next = state.substr(next_pos);
            for (auto&e : string_to_label)
                if (ds.find_set(e.second) == ds.find_set(string_to_label[word]))
                    solve(prev + e.first + next, pos + e.first.length());
        }
    }    
    
public:
    vector<string> generateSentences(vector<vector<string>>& synonyms, string text) {
       int count_label  = 0;
        for (auto &e : synonyms)
            for (auto &st : e)
                if (string_to_label.find(st) == string_to_label.end()) string_to_label[st] = count_label++;
        
        ds = DisjointSet(count_label);
        for (auto &e : synonyms)
            ds.union_set(string_to_label[e[0]], string_to_label[e[1]]);
        
        solve(text, 0);
        sort(result.begin(), result.end());
        return result;
    }
};
