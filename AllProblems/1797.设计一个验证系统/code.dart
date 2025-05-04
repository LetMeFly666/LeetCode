class AuthenticationManager {

  AuthenticationManager(int timeToLive) {
    
  }
  
  void generate(String tokenId, int currentTime) {
    
  }
  
  void renew(String tokenId, int currentTime) {
    
  }
  
  int countUnexpiredTokens(int currentTime) {
    
  }
}

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager obj = AuthenticationManager(timeToLive);
 * obj.generate(tokenId,currentTime);
 * obj.renew(tokenId,currentTime);
 * int param3 = obj.countUnexpiredTokens(currentTime);
 */