class AuthenticationManager {
    init(timeToLive: Int64) {

    }
    
    func generate(tokenId: String, currentTime: Int64): Unit {

    }
    
    func renew(tokenId: String, currentTime: Int64): Unit {

    }
    
    func countUnexpiredTokens(currentTime: Int64): Int64 {

    }
}

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * let obj: AuthenticationManager = AuthenticationManager(timeToLive)
 * obj.generate(tokenId,currentTime)
 * obj.renew(tokenId,currentTime)
 * let param_3 = obj.countUnexpiredTokens(currentTime)
 */