use std::collections::{HashMap,HashSet};

struct Twitter {
    tweets: HashMap<i32,Vec<(i32,i32)>>,
    followers: HashMap<i32,HashSet<i32>>,
    time:i32,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Twitter {

    fn new() -> Self {
        Twitter{
            tweets:HashMap::new(),
            followers:HashMap::new(),
            time:0,
        }
    }
    
    fn post_tweet(&mut self, user_id: i32, tweet_id: i32) {
        self.time+=1;
        self.tweets
            .entry(user_id).or_default().push((self.time,tweet_id));
    }
    
    fn get_news_feed(&self, user_id: i32) -> Vec<i32> {
        let mut new_feed=Vec::new();
        let mut following_id=HashSet::new();

        if let Some(followers) = self.followers.get(&user_id){
            following_id.extend(followers.iter());
        }
        
        following_id.insert(user_id);

        for &id in &following_id{
            if let Some(user_tweet) = self.tweets.get(&id){
                new_feed.extend(user_tweet.iter().cloned());
            }
        }

        new_feed.sort_unstable_by_key(|tweet|-tweet.0);
        new_feed.iter().take(10).map(|&(_, tweet_id)| tweet_id).collect()
    }
    
    fn follow(&mut self, follower_id: i32, followee_id: i32) {
        self.followers
            .entry(follower_id).or_default().insert(followee_id);
    }
    
    fn unfollow(&mut self, follower_id: i32, followee_id: i32) {   
        if let Some(follower)=self.followers.get_mut(&follower_id){
            follower.remove(&followee_id);
        }
    }
}

/**
 * Your Twitter object will be instantiated and called as such:
 * let obj = Twitter::new();
 * obj.post_tweet(userId, tweetId);
 * let ret_2: Vec<i32> = obj.get_news_feed(userId);
 * obj.follow(followerId, followeeId);
 * obj.unfollow(followerId, followeeId);
 */
