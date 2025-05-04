public class AuthenticationManager {

    public AuthenticationManager(int timeToLive) {
        
    }
    
    public void Generate(string tokenId, int currentTime) {
        
    }
    
    public void Renew(string tokenId, int currentTime) {
        
    }
    
    public int CountUnexpiredTokens(int currentTime) {
        
    }
}

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager obj = new AuthenticationManager(timeToLive);
 * obj.Generate(tokenId,currentTime);
 * obj.Renew(tokenId,currentTime);
 * int param_3 = obj.CountUnexpiredTokens(currentTime);
 */