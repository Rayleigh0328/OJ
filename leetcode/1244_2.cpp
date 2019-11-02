class Leaderboard {
    map<int,int,greater<int>> score_to_count;
    unordered_map<int,int> player_to_score;
    
public:
    Leaderboard() {    
    }
    
    void addScore(int player_id, int score) {
        int old_score=0;
        if (player_to_score.find(player_id) != player_to_score.end()){
            old_score = player_to_score[player_id];
            --score_to_count[old_score];
        }
        player_to_score[player_id] = score + old_score;
        ++score_to_count[score + old_score];
    }
    
    int top(int k) {
        int remain = k;
        int ans = 0;
        for (const auto &e : score_to_count){
            if (e.second < remain) {
                ans += e.first * e.second;
                remain -= e.second;
            }
            else {
                ans += e.first * remain;
                return ans;
            }
        }
        return -1;
    }
    
    void reset(int player_id) {
        int old_score = 0;
        if (player_to_score.find(player_id) != player_to_score.end()) old_score = player_to_score[player_id];
        addScore(player_id, -old_score);
    }
};
