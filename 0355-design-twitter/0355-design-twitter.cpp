class Twitter {
public:
    unordered_map<int, vector<pair<int,int>>> tweets;
    unordered_map<int, unordered_set<int>> following;
    int time;
    int k = 10;
    Twitter() {
        time=0;
    }
    
    void postTweet(int userId, int tweetId) {
        time++;
        tweets[userId].push_back({time,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<vector<int>> pq;
        vector<int> ans;
        if(!tweets[userId].empty()){
            int index = tweets[userId].size()-1;
            pq.push({tweets[userId][index].first,
            tweets[userId][index].second,userId,index});
        }
        for(auto fId : following[userId]){
            if(!tweets[fId].empty()){
                int index = tweets[fId].size()-1;
                pq.push({tweets[fId][index].first,
                tweets[fId][index].second,fId,index});
            }
        }
        //top[0]->time;
        //top[1]->tweetId;
        //top[2]->userId;
        //top[3]->index;
        while(!pq.empty() && ans.size()<k){
            auto top = pq.top();
            pq.pop();
            ans.push_back(top[1]);
            int nextIndex = top[3]-1;
            int userId = top[2];
            if(nextIndex>=0){
                pq.push({tweets[userId][nextIndex].first,
                tweets[userId][nextIndex].second,top[2],nextIndex});
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
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