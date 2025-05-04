class AuthenticationManager {
public:
    AuthenticationManager(int timeToLive) {
        
    }
    
    void generate(string tokenId, int currentTime) {
        
    }
    
    void renew(string tokenId, int currentTime) {
        
    }
    
    int countUnexpiredTokens(int currentTime) {
        
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */