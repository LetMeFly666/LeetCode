class AuthenticationManager(timeToLive: Int) {

    fun generate(tokenId: String, currentTime: Int) {
        
    }

    fun renew(tokenId: String, currentTime: Int) {
        
    }

    fun countUnexpiredTokens(currentTime: Int): Int {
        
    }

}

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * var obj = AuthenticationManager(timeToLive)
 * obj.generate(tokenId,currentTime)
 * obj.renew(tokenId,currentTime)
 * var param_3 = obj.countUnexpiredTokens(currentTime)
 */