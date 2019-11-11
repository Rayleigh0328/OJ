struct Tweet{
    int tweetId;
    int timestamp;
    
    Tweet(int tid, int ts):tweetId(tid),timestamp(ts){}
    
    bool operator<(const Tweet& other) const{
        return timestamp > other.timestamp;
    }
};

class Twitter {
    
    unordered_map<int, vector<Tweet>> user_to_tweets;
    unordered_map<int, unordered_set<int>> user_to_follows;
    int timestamp;
    
public:
    /** Initialize your data structure here. */
    Twitter() {
        timestamp = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        user_to_tweets[userId].push_back(Tweet(tweetId, ++timestamp));
        user_to_follows[userId].emplace(userId);
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        priority_queue<Tweet> que;
        
        for (auto id : user_to_follows[userId]){
            vector<Tweet>& v = user_to_tweets[id];
            for (auto rit = v.rbegin(); rit != v.rend(); ++rit){
                if (que.size() < 10) que.push(*rit);
                else {
                    if (rit->timestamp < que.top().timestamp) break;
                    else {
                        que.pop();
                        que.push(*rit);
                    }
                }
            }
        }
        vector<int> result;
        while (!que.empty()){
            result.push_back(que.top().tweetId);
            que.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        user_to_follows[followerId].emplace(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (followeeId == followerId) return;
        user_to_follows[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
