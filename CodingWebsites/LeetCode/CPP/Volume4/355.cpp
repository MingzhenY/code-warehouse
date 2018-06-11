#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <list>
#include <cmath>
#include <map>
#include <set>
#include <stack>
using namespace std;

class Twitter {
    int Time;
    map<int,map<int,int> > M;
    map<int,set<int>> F;
public:
    /** Initialize your data structure here. */
    Twitter() {
        Time = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        M[userId][++Time] = tweetId;
        if(M[userId].size() > 10){
            int key = M[userId].begin()->first;
            M[userId].erase(key);
        }
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        map<int,int> NF;
        for(auto x : M[userId]){
            NF[x.first] = x.second;
        }
        for(auto f : F[userId]){
            for(auto x : M[f]){
                NF[x.first] = x.second;
            }
        }
        vector<int> ret;
        int C = 0;
        for(auto x = NF.rbegin() ; x != NF.rend() ; ++x){
            if(C < 10){
                ++C;
                ret.push_back(x->second);
            }
            else
                break;
        }
        return ret;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        F[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        F[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */

int main(){
    Twitter S;
    S.Test();
	return 0;
}
