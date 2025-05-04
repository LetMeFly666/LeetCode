class AuthenticationManager {

    public AuthenticationManager(int timeToLive) {
        
    }
    
    public void generate(String tokenId, int currentTime) {
        
    }
    
    public void renew(String tokenId, int currentTime) {
        
    }
    
    public int countUnexpiredTokens(int currentTime) {
        
    }
}

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager obj = new AuthenticationManager(timeToLive);
 * obj.generate(tokenId,currentTime);
 * obj.renew(tokenId,currentTime);
 * int param_3 = obj.countUnexpiredTokens(currentTime);
 */