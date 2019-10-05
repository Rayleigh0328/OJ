class Solution {
    
    unordered_set<string> result_set;
    
    void solve(string current, string tiles){
        // cout << "try " << current << " with " << tiles << endl;
        for (int i=0;i<tiles.length();++i){
            string next_st = current + tiles[i];
            string next_tiles = tiles;
            next_tiles.erase(i,1);
            result_set.emplace(next_st);
            solve(next_st, next_tiles);
        }
    }
    
public:
    int numTilePossibilities(string tiles) {
        result_set.clear();
        solve("", tiles);
        return result_set.size();
    }
};
