
class AuthenticationManager {

    init(_ timeToLive: Int) {
        
    }
    
    func generate(_ tokenId: String, _ currentTime: Int) {
        
    }
    
    func renew(_ tokenId: String, _ currentTime: Int) {
        
    }
    
    func countUnexpiredTokens(_ currentTime: Int) -> Int {
        
    }
}

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * let obj = AuthenticationManager(timeToLive)
 * obj.generate(tokenId, currentTime)
 * obj.renew(tokenId, currentTime)
 * let ret_3: Int = obj.countUnexpiredTokens(currentTime)
 */