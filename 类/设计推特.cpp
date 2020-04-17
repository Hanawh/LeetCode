class Twitter {
public:
    /** Initialize your data structure here. */
    unordered_map<int, set<int> > user;//存储该用户和其关注者 双向链表
    vector<pair<int, int> > post; //所有发的帖子 userID, tweetID

    Twitter() {
        user.clear();
        post.clear();
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        post.push_back(make_pair(userId, tweetId));
        user[userId].insert(userId);
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        if(user.find(userId)==user.end()) return res;
        int count = 10;
        set<int> s = user[userId];
        for(int i=post.size()-1; i>=0; i--){
            auto [key, val] = post[i];
            if(count>0 and s.find(key)!=s.end()){
                res.push_back(val);
                count--;
            }
        }
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        user[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(user.find(followerId)==user.end() or followerId==followeeId) return;
        user[followerId].erase(followeeId);
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
