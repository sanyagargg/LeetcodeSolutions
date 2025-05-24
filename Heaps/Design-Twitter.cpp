class Twitter {
private:
    int time;
    unordered_map<int, unordered_set<int>> follows;
    unordered_map<int, vector<pair<int, int>>> tweets;

public:
    Twitter() {
        time = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].emplace_back(time++, tweetId);
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> maxHeap;
        follows[userId].insert(userId); // ensure user follows self

        for (int followee : follows[userId]) {
            auto& t = tweets[followee];
            for (int i = max(0, (int)t.size() - 10); i < t.size(); ++i) {
                maxHeap.push(t[i]);
            }
        }

        vector<int> res;
        while (!maxHeap.empty() && res.size() < 10) {
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return res;
    }

    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            follows[followerId].erase(followeeId);
        }
    }
};
