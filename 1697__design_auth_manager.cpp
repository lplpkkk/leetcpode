class AuthenticationManager {
private:
    int ttl;
    unordered_map<string, int> expire;

public:
    AuthenticationManager(int timeToLive) {
        ttl=timeToLive;    
    }
    
    void generate(string tokenId, int currentTime) {
        expire[tokenId]=currentTime+ttl;
    }
    
    void renew(string tokenId, int currentTime) {
        if(expire.count(tokenId) && currentTime<expire[tokenId]){
            expire[tokenId]=currentTime+ttl;
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        int cnt=0;
        for(auto&[token,t]: expire){
            if(t>currentTime){
                cnt++;
            }
        }

        return cnt;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */
