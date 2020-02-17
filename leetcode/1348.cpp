class TweetCounts {
    
    unordered_map<string, multiset<int>> mp;
    
    vector<int> retrieve_timestamps(const string &name, int start, int end){
        if (mp.find(name) == mp.end()) return {};
        multiset<int>& ms = mp.find(name)->second;
        multiset<int>::iterator it = ms.lower_bound(start);
        vector<int> result;
        while (it != ms.end() && *it <= end){
            result.push_back(*it);
            ++it;
        }
        return result;
    }
    
    int get_window(const string &freq){
        if (freq == "minute") return 60;
        else if (freq == "hour") return 60 * 60;
        else return 24 * 60 * 60;
    }
    
public:
    TweetCounts() {
        mp.clear();
    }
    
    void recordTweet(string tweetName, int time) {
        mp[tweetName].emplace(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        vector<int> a = retrieve_timestamps(tweetName, startTime, endTime);
        int window = get_window(freq);
        // printf("window: %d\n", window);
        vector<int> result( ceil((endTime - startTime + 1) / static_cast<double>(window)) , 0);
        for (auto x : a){
            ++result[(x-startTime)/window];
        }
            
        return result;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
